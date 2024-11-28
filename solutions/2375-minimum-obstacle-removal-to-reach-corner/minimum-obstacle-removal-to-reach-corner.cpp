#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define INL_ATTR noexcept INL NO_SAN HOT
#define OUTL_ATTR noexcept NO_SAN HOT

template <class T, class S, S cap>
struct ring_queue {
    S start, end;
    T elem[cap];

    ring_queue() INL_ATTR: start(0), end(0) {}

    void push(const T v) INL_ATTR {
        elem[end++] = v;
        if (end >= cap) end = 0;
        // assert(!empty());
    }

    T pop() INL_ATTR {
        const T r = elem[start++];
        if (start >= cap) start = 0;
        return r;
    }

    bool empty() INL_ATTR {
        return start == end;
    }
};

class Solution {
public:
    static int minimumObstacles(vector<vector<int>>& grid) OUTL_ATTR {
        const uint m = grid.size(), n = grid.front().size();
        const uint8_t nord = 32 - countl_zero(n);
        const uint cmask = (1u << nord) - 1u, endcoo = ((m - 1u) << nord) + n - 1u;
        constexpr uint QCAP = 100'000;
        ring_queue<uint, uint, QCAP> que[2];
        que[0].push(0);
        uint cost = 0;
        bool a = false;
        grid.front().front() = -1;
        while (!que[a].empty()) {
            while (!que[a].empty()) {
                const uint coo = que[a].pop();
                const uint i = coo >> nord, j = coo & cmask;
                if (int b = !!i, &g = grid[i-b][j]; b & g >= 0) {
                    que[a^g].push(coo - cmask - 1u);
                    g = -1;
                }
                if (int b = i + 1u < m, &g = grid[i+b][j]; b & g >= 0) {
                    if (coo + cmask + 1u == endcoo) [[unlikely]]
                        return cost + g;
                    que[a^g].push(coo + cmask + 1u);
                    g = -1;
                }
                if (int b = !!j, &g = grid[i][j-b]; b & g >= 0) {
                    que[a^g].push(coo - 1u);
                    g = -1;
                }
                if (int b = j + 1u < n, &g = grid[i][j+b]; b & g >= 0) {
                    if (coo + 1u == endcoo) [[unlikely]]
                        return cost + g;
                    que[a^g].push(coo + 1u);
                    g = -1;
                }
            }
            cost++;
            a = !a;
        }
        return -1; // unreachable
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();