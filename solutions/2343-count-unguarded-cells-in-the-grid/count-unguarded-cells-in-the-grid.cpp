#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))

class Solution {
private:
    static constexpr uint MAXS = 100'000;
    static constexpr uint MAXC = (MAXS + 31u) >> 5;
    static constexpr uint64_t BIT_MASK = 0x5555555555555555ull;

    enum object_t : uint8_t { empty = 0, spied, guard, wall };

    alignas(64) static uint64_t grid[MAXC];

    static object_t get(const uint idx) noexcept {
        return static_cast<object_t>((grid[idx >> 5] >> ((idx & 31) << 1)) & 3u);
    }

    static void set(const uint idx, const object_t v) noexcept {
        const uint shift = (idx & 31) << 1;
        grid[idx >> 5] = (grid[idx >> 5] & ~(3ull << shift)) | (uint64_t(v) << shift);
    }

public:
    static int countUnguarded(uint m, uint n, 
                            const vector<vector<int>>& guards,
                            const vector<vector<int>>& walls) noexcept {
        const uint size = m * n;
        const uint qsize = (size + 31u) >> 5;
        
        __builtin_memset(grid, 0, qsize * sizeof(uint64_t));

        const uint guard_size = guards.size();
        const uint wall_size = walls.size();
        
        if (__builtin_expect(guard_size + wall_size == size, 0)) return 0;
        
        #pragma GCC unroll 4
        for (uint i = 0; i < wall_size; ++i) {
            set(walls[i][0] * n + walls[i][1], wall);
        }
        
        #pragma GCC unroll 4
        for (uint i = 0; i < guard_size; ++i) {
            set(guards[i][0] * n + guards[i][1], guard);
        }

        #pragma GCC unroll 2
        for (uint g = 0; g < guard_size; ++g) {
            const uint x = guards[g][0], y = guards[g][1];
            
            for (uint i = x - 1u, d = i * n + y; i + 1u && get(d) <= spied; i--, d -= n)
                set(d, spied);
            for (uint i = x + 1u, d = i * n + y; i < m && get(d) <= spied; i++, d += n)
                set(d, spied);
            for (uint j = y - 1u, d = x * n + j; j + 1u && get(d) <= spied; j--, d--)
                set(d, spied);
            for (uint j = y + 1u, d = x * n + j; j < n && get(d) <= spied; j++, d++)
                set(d, spied);
        }

        uint guarded = 0;
        #pragma GCC unroll 8
        for (uint k = 0; k < qsize; ++k) {
            guarded += __builtin_popcountll((grid[k] | (grid[k] >> 1)) & BIT_MASK);
        }

        return size - guarded;
    }
};

alignas(64) uint64_t Solution::grid[MAXC];

[[maybe_unused]] static const auto fast_io = []() noexcept {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();