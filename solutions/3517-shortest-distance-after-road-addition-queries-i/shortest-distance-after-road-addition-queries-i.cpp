#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define INL_ATTR noexcept INL NO_SAN HOT
#define OUTL_ATTR noexcept NO_SAN HOT
#define LAM_ATTR INL NO_SAN HOT noexcept

class Solution {
private:
    static constexpr uint16_t MAXN = 500;

    static bitset<MAXN> adj[MAXN];

    static void cleanup(const uint16_t n) INL_ATTR {
        const uint8_t nq = (n + 63u) >> 6;
        {
            uint64_t *const p = (uint64_t*)adj;
            fill(p, p + nq, 0);
        }
        for (uint16_t i = 1; i < n; i++) {
            uint64_t *const p = (uint64_t*)(adj + i);
            fill(p, p + nq, 0);
            adj[i].set(i - 1u);
        }
    }

    static void recalc(const uint16_t n, const uint16_t c, uint16_t dist[]) OUTL_ATTR {
        const uint16_t dc = dist[c] + 1u;
        const uint8_t nq = (n + 63u) >> 6;
        const uint64_t *const p = (const uint64_t*)(adj + c);
        for (uint8_t j = 0; j < nq; j++) {
            const uint16_t b = j << 6;
            for (uint64_t q = p[j]; q; ) {
                const uint8_t i = countr_zero(q);
                const uint16_t k = b + i;
                if (uint16_t &dk = dist[k]; dk > dc) {
                    dk = dc;
                    recalc(n, k, dist);
                }
                q ^= 1ull << i;
            }
        }
    }

public:
    static vector<int> shortestDistanceAfterQueries(const uint16_t n, vector<vector<int>>& queries) OUTL_ATTR {
        uint16_t dist[n], d = n;
        generate_n(dist, n, [&d]() LAM_ATTR { return --d; });

        const uint16_t m = queries.size();
        vector<int> &r = queries.front();
        {
            const uint16_t a = r[0], b = r[1];
            adj[b].set(a);
            dist[a] = min(dist[a] + 0u, dist[b] + 1u);
            recalc(n, a, dist);
            r.clear();
            r.reserve(m);
            r.push_back(*dist);
        }
        for (uint16_t i = 1; i < m; i++) {
            const uint16_t a = queries[i][0], b = queries[i][1];
            adj[b].set(a);
            dist[a] = min(dist[a] + 0u, dist[b] + 1u);
            recalc(n, a, dist);
            r.push_back(*dist);
        }
        cleanup(n);
        return move(r);
    }

    static void init() INL_ATTR {
        for (uint16_t i = 1; i < MAXN; i++)
            adj[i].set(i - 1u);
    }
};

bitset<Solution::MAXN> Solution::adj[MAXN];

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution::init();
    return 'c';
}();