class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int len = queries.size();

        vector<long long> pre(n, 0);
        vector<long long> suff(n, 0);

        for (int i = 0; i < n - 1; i++) {
            long long diffFromRight = (long long) nums[i + 1] - nums[i];
            long long diffFromLeft = (i > 0)
                ? (long long) nums[i] - nums[i - 1]
                : LLONG_MAX;

            pre[i + 1] = pre[i] + (diffFromRight < diffFromLeft ? 1 : diffFromRight);
        }

        for (int i = n - 1; i > 0; i--) {
            long long diffFromLeft = (long long) nums[i] - nums[i - 1];
            long long diffFromRight = (i < n - 1)
                ? (long long) nums[i + 1] - nums[i]
                : LLONG_MAX;

            suff[i - 1] = suff[i] + (diffFromLeft <= diffFromRight ? 1 : diffFromLeft);
        }

        vector<int> ans(len);

        for (int i = 0; i < len; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            if (l <= r) {
                ans[i] = (int)(pre[r] - pre[l]);
            } else {
                ans[i] = (int)(suff[r] - suff[l]);
            }
        }

        return ans;
    }
};