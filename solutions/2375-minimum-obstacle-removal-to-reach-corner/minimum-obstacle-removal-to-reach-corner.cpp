#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define COLD __attribute__((cold))
#define PURE __attribute__((pure))
#define CONST __attribute__((const))
#define FLATTEN __attribute__((flatten))
#define INL_ATTR noexcept INL NO_SAN HOT FLATTEN
#define OUTL_ATTR noexcept NO_SAN HOT FLATTEN

template <class T, class S, S cap>
struct ring_queue {
    S start, end;
    alignas(64) T elem[cap];

    ring_queue() INL_ATTR : start(0), end(0) {}

    void push(const T v) INL_ATTR {
        elem[end] = v;
        end = (end + 1) & (cap - 1);
    }

    T pop() INL_ATTR {
        const T r = elem[start];
        start = (start + 1) & (cap - 1);
        return r;
    }

    bool empty() const INL_ATTR PURE {
        return start == end;
    }
};

class Solution {
    static constexpr uint QCAP = 1 << 17;
public:
    static int minimumObstacles(vector<vector<int>>& grid) OUTL_ATTR {
        if (grid.empty() || grid[0].empty()) return 0;
        
        const uint m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 0;
        
        const uint8_t nord = 32 - __builtin_clz(n);
        const uint cmask = (1u << nord) - 1u;
        const uint endcoo = ((m - 1u) << nord) + n - 1u;
        
        alignas(64) ring_queue<uint, uint, QCAP> que[2];
        que[0].push(0);
        uint cost = 0;
        bool a = false;
        grid[0][0] = -1;

        do {
            while (!que[a].empty()) {
                const uint coo = que[a].pop();
                const uint i = coo >> nord, j = coo & cmask;

                if (i > 0 && grid[i-1][j] >= 0) {
                    que[a^grid[i-1][j]].push(coo - cmask - 1u);
                    grid[i-1][j] = -1;
                }
                if (i + 1 < m && grid[i+1][j] >= 0) {
                    if (coo + cmask + 1u == endcoo) [[unlikely]]
                        return cost + grid[i+1][j];
                    que[a^grid[i+1][j]].push(coo + cmask + 1u);
                    grid[i+1][j] = -1;
                }
                if (j > 0 && grid[i][j-1] >= 0) {
                    que[a^grid[i][j-1]].push(coo - 1u);
                    grid[i][j-1] = -1;
                }
                if (j + 1 < n && grid[i][j+1] >= 0) {
                    if (coo + 1u == endcoo) [[unlikely]]
                        return cost + grid[i][j+1];
                    que[a^grid[i][j+1]].push(coo + 1u);
                    grid[i][j+1] = -1;
                }
            }
            cost++;
            a ^= 1;
        } while (!que[a].empty());

        return -1;
    }
};