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
        const uint64_t mask = 3ull << shift;
        grid[idx >> 5] = (grid[idx >> 5] & ~mask) | (uint64_t(v) << shift);
    }

public:
    static int countUnguarded(const uint m, const uint n, 
                            const vector<vector<int>>& guards,
                            const vector<vector<int>>& walls) noexcept {
        const uint size = m * n;
        const uint qsize = (size + 31u) >> 5;
        
        memset(grid, 0, qsize * sizeof(uint64_t));

        for (const auto& w : walls) {
            set(w[0] * n + w[1], wall);
        }
        for (const auto& g : guards) {
            set(g[0] * n + g[1], guard);
        }

        for (const auto& g : guards) {
            const uint x = g[0], y = g[1];
            
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
        for (uint k = 0; k < qsize; k++) {
            const uint64_t q = grid[k];
            guarded += __builtin_popcountll((q | (q >> 1)) & BIT_MASK);
        }

        return size - guarded;
    }
};

alignas(64) uint64_t Solution::grid[MAXC];

static auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
