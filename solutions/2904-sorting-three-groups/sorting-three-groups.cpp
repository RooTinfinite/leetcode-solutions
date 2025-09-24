class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (3, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = (nums[i - 1] != 1) + dp[i - 1][0];
            dp[i][1] = (nums[i - 1] != 2) + min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][2] = (nums[i - 1] != 3) + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        }
        return min({dp[n][0], dp[n][1], dp[n][2]});
    }
};