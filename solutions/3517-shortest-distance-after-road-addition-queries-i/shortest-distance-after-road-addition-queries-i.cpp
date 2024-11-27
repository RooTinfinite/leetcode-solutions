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
        for (uint16_t i = 0; i < n; i++) {
            g[i].reset();
        }
        for (uint16_t i = 1; i < n; i++) {
            g[i].set(i - 1u);
        }
    }

    static void update(const uint16_t n, const uint16_t c, uint16_t d[]) ATTR {
        const uint16_t dc = d[c] + 1u;
        for (uint16_t k = 0; k < n; k++) {
            if (g[c][k] && d[k] > dc) {
                d[k] = dc;
                update(n, k, d);
            }
        }
    }

public:
    static vector<int> shortestDistanceAfterQueries(const uint16_t n, vector<vector<int>>& q) ATTR {
        uint16_t v = n;
        generate_n(d, n, [&v]() noexcept { return --v; });

        vector<int> r;
        r.reserve(q.size());
        
        for (const auto& query : q) {
            const uint16_t a = query[0], b = query[1];
            g[b].set(a);
            d[a] = min<uint16_t>(d[a], d[b] + 1u);
            update(n, a, d);
            r.push_back(d[0]);
        }
        
        reset(n);
        return r;
    }

    static void init() ATTR {
        for (uint16_t i = 1; i < N; i++) {
            g[i].set(i - 1u);
        }
    }
};

bitset<Solution::N> Solution::g[Solution::N];
uint16_t Solution::d[Solution::N];

static const auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution::init();
    return 0;
}();