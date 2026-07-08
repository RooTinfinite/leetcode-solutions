class Solution {
public:
    long long r(vector<int> &nums, int pos, bool skip, vector<vector<long long>> &dp) {
        int n = nums.size();
        if (pos >= n - 1) return 0;
        if (dp[skip][pos] != -1) return dp[skip][pos];

        long long ans = max(0, max(nums[pos - 1], nums[pos + 1]) + 1 - nums[pos]);
        
        if (skip) 
            return dp[skip][pos] = ans + r(nums, pos + 2, skip, dp);

        dp[true][pos]  = ans + r(nums, pos + 3, true, dp);
        dp[false][pos] = ans + r(nums, pos + 2, false, dp);

        return min(dp[0][pos], dp[1][pos]);
    }
    
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        
        // Odd length: fixed pattern
        if (n % 2) {
            long long ans = 0;
            for (int i = 1; i < n - 1; i += 2) {
                ans += max(0, max(nums[i-1], nums[i+1]) + 1 - nums[i]);
            }
            return ans;                    
        }
        
        // Even length: DP with skip
        vector<vector<long long>> dp(2, vector<long long>(n, -1));
        
        return min(r(nums, 1, false, dp), r(nums, 2, true, dp));
    }
};