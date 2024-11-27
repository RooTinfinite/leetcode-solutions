#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define ATTR noexcept INL NO_SAN HOT

class Solution {
private:
    static constexpr uint16_t N = 500;
    static bitset<N> g[N];
    static uint16_t d[N];

    static void reset(const uint16_t n) ATTR {
        const uint8_t nq = (n + 63u) >> 6;
        uint64_t *p = (uint64_t*)g;
        fill(p, p + nq, 0);
        
        for (uint16_t i = 1; i < n; i++) {
            p = (uint64_t*)(g + i);
            fill(p, p + nq, 0);
            g[i].set(i - 1u);
        }
    }

    static void update(const uint16_t n, const uint16_t c, uint16_t d[]) ATTR {
        const uint16_t dc = d[c] + 1u;
        const uint8_t nq = (n + 63u) >> 6;
        const uint64_t *p = (const uint64_t*)(g + c);
        
        for (uint8_t j = 0; j < nq; j++) {
            uint64_t q = p[j];
            while (q) {
                const uint64_t isolated_bit = q & -q;
                const uint8_t i = __builtin_ctzll(q);
                const uint16_t k = (j << 6) + i;
                
                if (uint16_t &dk = d[k]; dk > dc) {
                    dk = dc;
                    update(n, k, d);
                }
                q &= (q - 1);
            }
        }
    }

public:
    static vector<int> shortestDistanceAfterQueries(const uint16_t n, vector<vector<int>>& q) ATTR {
        uint16_t v = n;
        generate_n(d, n, [&v]() noexcept { return --v; });

        const uint16_t m = q.size();
        vector<int> &r = q.front();
        
        const uint16_t a = r[0], b = r[1];
        g[b].set(a);
        d[a] = std::min<uint16_t>(d[a], static_cast<uint16_t>(d[b] + 1u));
        update(n, a, d);
        r.clear();
        r.reserve(m);
        r.push_back(*d);

        for (uint16_t i = 1; i < m; i++) {
            const uint16_t a = q[i][0], b = q[i][1];
            g[b].set(a);
            d[a] = std::min<uint16_t>(d[a], static_cast<uint16_t>(d[b] + 1u));
            update(n, a, d);
            r.push_back(*d);
        }
        reset(n);
        return std::move(r);
    }

    static void init() ATTR {
        for (uint16_t i = 1; i < N; i++)
            g[i].set(i - 1u);
    }
};

bitset<Solution::N> Solution::g[Solution::N];
uint16_t Solution::d[Solution::N];

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution::init();
    return 'c';
}();