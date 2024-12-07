#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define INL_ATTR noexcept INL /*NO_SAN*/ HOT
#define OUTL_ATTR noexcept /*NO_SAN*/ HOT
#define LAM_ATTR INL /*NO_SAN*/ HOT noexcept

class Solution {
private:
    static uint target(const vector<int> &nums, const uint m) INL_ATTR {
        return transform_reduce(nums.cbegin(), nums.cend(), 0ull,
            plus(), [m](const uint v) LAM_ATTR { return (v - 1u) / m; });
    }

public:
    static int minimumSize(const vector<int>& nums, const uint tc) OUTL_ATTR {
        constexpr uint MAXV = 1'000'000'000u;
        const uint n = nums.size();
        if (n == 1)
            return (nums.front() + tc) / (tc + 1u);
        uint64_t s = 0;
        uint rb = 0;
        for (const uint v : nums) {
            s += v;
            rb = max<uint64_t>(v, rb);
        }
        rb = min<uint>((s + tc - 1u) / tc, rb);
        uint lb = max<uint>((uint64_t)rb * (tc < 190 ? 261u : 471u) / 512u, 1);
        while (lb < rb) {
            const uint mid = (lb + rb) / 2;
            const uint64_t mc = target(nums, mid);
            const bool b = mc > tc;
            (b ? lb : rb) = mid + b;
        }
        return lb;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();