class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const long long NEG = LLONG_MIN / 2;
        long long ans = NEG, plus = NEG, minus = NEG, plusDel = NEG, minusDel = NEG;
        for (long long x : nums) {
            long long p = max(x, minus + x);  // start fresh at x, or add x after a minus
            long long m = plus - x;  // subtract x after a plus
            long long pd = max(minusDel + x, plus);  // add x after a minus with deletion used, or delete x
            long long md = max(plusDel - x, minus);  // subtract x after a plus with deletion used, or delete x
            plus = p, minus = m, plusDel = pd, minusDel = md;
            ans = max({ans, plus, minus, plusDel, minusDel});
        }
        return ans;
    }
};