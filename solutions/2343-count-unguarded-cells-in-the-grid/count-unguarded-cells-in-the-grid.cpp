#define NO_SAN __attribute__((no_sanitize("undefined","address","coverage","thread")))
#define INL inline __attribute__((always_inline))
#define HOT __attribute__((hot))

class Solution {
private:
    static constexpr uint32_t MAXS = 100'000;
    static constexpr uint32_t MAXC = (MAXS + 31u) >> 5;
    static constexpr uint64_t MASK = 0x5555555555555555ull;

    enum object_t : uint8_t { empty = 0, spied, guard, wall };
    
    alignas(64) static uint64_t grid[MAXC];

    static INL NO_SAN HOT object_t get(const uint32_t idx) {
        return static_cast<object_t>((grid[idx >> 5] >> ((idx & 31) << 1)) & 3u);
    }

    static INL NO_SAN HOT void set(const uint32_t idx, const object_t v) {
        const uint32_t sh = (idx & 31) << 1;
        const uint64_t mask = 3ull << sh;
        grid[idx >> 5] = (grid[idx >> 5] & ~mask) | (uint64_t(v) << sh);
    }

public:
    static int countUnguarded(const uint32_t m, const uint32_t n, const vector<vector<int>>& guards, const vector<vector<int>>& walls) NO_SAN HOT {
        for (const auto& w : walls) {
            set(uint32_t(w[0]) * n + w[1], wall);
        }
        for (const auto& g : guards) {
            set(uint32_t(g[0]) * n + g[1], guard);
        }

        for (const auto& g : guards) {
            const uint32_t x = g[0], y = g[1];
            const uint32_t xn = x * n;
            
            for (uint32_t i = x - 1, d = i * n + y; i < MAXS && get(d) <= spied; --i, d -= n) set(d, spied);
            for (uint32_t i = x + 1, d = i * n + y; i < m && get(d) <= spied; ++i, d += n) set(d, spied);
            for (uint32_t j = y - 1, d = xn + j; j < MAXS && get(d) <= spied; --j, --d) set(d, spied);
            for (uint32_t j = y + 1, d = xn + j; j < n && get(d) <= spied; ++j, ++d) set(d, spied);
        }

        const uint32_t size = m * n;
        const uint32_t qsize = (size + 31u) >> 5;
        uint32_t count = 0;

        for (uint32_t k = 0; k < qsize; ++k) {
            const uint64_t q = grid[k];
            count += __builtin_popcountll((q | (q >> 1)) & MASK);
        }

        memset(grid, 0, qsize * sizeof(uint64_t));
        return size - count;
    }
};

alignas(64) uint64_t Solution::grid[MAXC];

static const auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();