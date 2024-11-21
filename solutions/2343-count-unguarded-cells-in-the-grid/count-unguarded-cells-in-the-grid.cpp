#define NO_SANITIZE __attribute__((no_sanitize("undefined", "address", "thread", "memory", "leak")))
#define ALWAYS_INLINE __attribute__((always_inline)) inline
#define HOT __attribute__((hot, optimize("O3", "unroll-loops", "fast-math")))
#define PURE __attribute__((pure))
#define CONST __attribute__((const))
#define FLATTEN __attribute__((flatten))
#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)
#define ALIGNED(x) __attribute__((aligned(x)))
#define PREFETCH(x) __builtin_prefetch(x)

class Solution {
private:
    static constexpr uint MAXS = 100'000;
    static constexpr uint MAXC = (MAXS + 31u) >> 5;
    static constexpr uint64_t BIT_MASK = 0x5555555555555555ull;

    enum object_t : uint8_t { empty = 0, spied, guard, wall };

    ALIGNED(64) static uint64_t grid[MAXC];

    ALWAYS_INLINE PURE
    static object_t get(const uint idx) noexcept {
        return static_cast<object_t>((grid[idx >> 5] >> ((idx & 31) << 1)) & 3u);
    }

    ALWAYS_INLINE
    static void set(const uint idx, const object_t v) noexcept {
        const uint shift = (idx & 31) << 1;
        grid[idx >> 5] = (grid[idx >> 5] & ~(3ull << shift)) | (uint64_t(v) << shift);
    }

public:
    HOT NO_SANITIZE FLATTEN
    static int countUnguarded(uint m, uint n, 
                            const vector<vector<int>>& guards,
                            const vector<vector<int>>& walls) noexcept {
        const uint size = m * n;
        const uint qsize = (size + 31u) >> 5;
        
        __builtin_memset(grid, 0, qsize * sizeof(uint64_t));

        const uint guard_size = guards.size();
        const uint wall_size = walls.size();
        
        if (UNLIKELY(guard_size + wall_size == size)) return 0;
        
        #pragma GCC ivdep
        #pragma GCC unroll 8
        for (uint i = 0; i < wall_size; ++i) {
            const uint pos = walls[i][0] * n + walls[i][1];
            PREFETCH(&grid[pos >> 5]);
            set(pos, wall);
        }
        
        #pragma GCC ivdep
        #pragma GCC unroll 8
        for (uint i = 0; i < guard_size; ++i) {
            const uint pos = guards[i][0] * n + guards[i][1];
            PREFETCH(&grid[pos >> 5]);
            set(pos, guard);
        }

        #pragma GCC unroll 4
        for (uint g = 0; g < guard_size; ++g) {
            const uint x = guards[g][0], y = guards[g][1];
            const uint base = x * n;
            
            #pragma GCC ivdep
            for (uint i = x - 1u, d = i * n + y; i + 1u && get(d) <= spied; i--, d -= n) {
                PREFETCH(&grid[(d-n) >> 5]);
                set(d, spied);
            }
            
            #pragma GCC ivdep
            for (uint i = x + 1u, d = i * n + y; i < m && get(d) <= spied; i++, d += n) {
                PREFETCH(&grid[(d+n) >> 5]);
                set(d, spied);
            }
            
            #pragma GCC ivdep
            for (uint j = y - 1u, d = base + j; j + 1u && get(d) <= spied; j--, d--) {
                PREFETCH(&grid[(d-1) >> 5]);
                set(d, spied);
            }
            
            #pragma GCC ivdep
            for (uint j = y + 1u, d = base + j; j < n && get(d) <= spied; j++, d++) {
                PREFETCH(&grid[(d+1) >> 5]);
                set(d, spied);
            }
        }

        uint guarded = 0;
        #pragma GCC ivdep
        #pragma GCC unroll 16
        for (uint k = 0; k < qsize; ++k) {
            PREFETCH(&grid[k + 1]);
            guarded += __builtin_popcountll((grid[k] | (grid[k] >> 1)) & BIT_MASK);
        }

        return size - guarded;
    }
};

ALIGNED(64) uint64_t Solution::grid[MAXC];

[[maybe_unused]] static const auto fast_io = []() noexcept {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();