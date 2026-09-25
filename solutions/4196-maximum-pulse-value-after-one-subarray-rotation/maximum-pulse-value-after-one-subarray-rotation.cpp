class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        long long ans = 1e18;
        long long s = 0;

        long long e = 0;
        long long o = -1e18;

        for (int i = 0; i < n; i++) {

            // Alternating prefix sum
            s += (i % 2 == 0 ? nums[i] : -nums[i]);

            if ((i + 1) % 2 == 0) {

                ans = min(s - e, ans);
                e = max(e, s);

            } else {

                ans = min(s - o, ans);
                o = max(o, s);
            }
        }

        // Apply the best possible improvement
        s -= (2 * min(0LL, ans));

        return s;
    }
};