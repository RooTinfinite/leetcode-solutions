class Solution {
public:
    long long eval(vector<int> &nums, int start, int end, int k, vector<int> &cost) {
        int n = nums.size();

        vector<vector<long long>> dp(n + 2, vector<long long>(k + 1, INT_MAX));
        dp[start][0] = 0;

        for (int i = start; i <= end; i++) {
            for (int j = 0; j <= k; j++) {
                if (dp[i][j] == INT_MAX) continue;

                // Skip current
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

                // Take current
                if (j + 1 <= k) {
                    dp[i + 2][j + 1] = min(dp[i + 2][j + 1], dp[i][j] + cost[i]);
                }
            }
        }

        return min(dp[end + 1][k], dp[end + 2][k]);
    }
    
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n / 2) return -1;
        if (k == 0) return 0;
        if (n == 2) return nums[0] == nums[1] ? 1 : 0;

        vector<int> cost(n);
        for (int i = 0; i < n; i++) {
            int left = nums[(i - 1 + n) % n];
            int right = nums[(i + 1) % n];
            cost[i] = max(0, max(left, right) + 1 - nums[i]);
        }

        long long ans = INT_MAX;

        // Case 1: skip index 0
        ans = min(ans, eval(nums, 1, n - 1, k, cost));

        // Case 2: take index 0
        if (k >= 1) {
            long long val = cost[0] + eval(nums, 2, n - 2, k - 1, cost);
            ans = min(ans, val);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};