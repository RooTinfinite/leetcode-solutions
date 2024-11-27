#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define ATTR noexcept INL NO_SAN HOT

class Solution {
private:
    static constexpr uint16_t N = 500;
    alignas(64) static bitset<N> g[N];
    alignas(64) static uint16_t d[N];

    static void reset(const uint16_t n) ATTR {
        memset(g, 0, sizeof(bitset<N>) * n);
        for (uint16_t i = 1; i < n; i++) {
            g[i].set(i - 1u);
        }
    }

    static void update(const uint16_t n, const uint16_t c) ATTR {
        const uint16_t dc = d[c] + 1u;
        const uint8_t nq = (n + 63u) >> 6;
        const uint64_t *p = (const uint64_t*)(g + c);
        
        uint64_t q;
        for (uint8_t j = 0; j < nq; j++) {
            for (q = p[j]; q; q &= q - 1) {
                const uint16_t k = (j << 6) + __builtin_ctzll(q);
                if (d[k] > dc) {
                    d[k] = dc;
                    update(n, k);
                }
            }
        }
    }

public:
    static vector<int> shortestDistanceAfterQueries(const uint16_t n, vector<vector<int>>& q) ATTR {
        uint16_t v = n;
        for (uint16_t i = 0; i < n; ++i) d[i] = --v;

        const uint16_t m = q.size();
        vector<int>& r = q.front();
        
        {
            const uint16_t a = r[0], b = r[1];
            g[b].set(a);
            if (d[a] > d[b] + 1u) {
                d[a] = d[b] + 1u;
                update(n, a);
            }
        }
        
        r.clear();
        r.reserve(m);
        r.push_back(d[0]);

        for (uint16_t i = 1; i < m; ++i) {
            const uint16_t a = q[i][0], b = q[i][1];
            g[b].set(a);
            if (d[a] > d[b] + 1u) {
                d[a] = d[b] + 1u;
                update(n, a);
            }
            r.push_back(d[0]);
        }
        
        reset(n);
        return std::move(r);
    }

    static void init() ATTR {
        for (uint16_t i = 1; i < N; i++) {
            g[i].set(i - 1u);
        }
    }
};

alignas(64) bitset<Solution::N> Solution::g[Solution::N];
alignas(64) uint16_t Solution::d[Solution::N];

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution::init();
    return 'c';
}();