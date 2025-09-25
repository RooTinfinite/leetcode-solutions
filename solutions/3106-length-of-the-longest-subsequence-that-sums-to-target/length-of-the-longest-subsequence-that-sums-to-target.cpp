class Solution {
public:
    int n;
    int solve(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(idx<0 || target<0) return 0;
        if(idx == 0) {
            if(nums[0] == target) return 1;
            return 0;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        int notTake = solve(idx-1, target, nums, dp);
        int take = 0;
        if(nums[idx] <= target) {
            int next = solve(idx-1, target-nums[idx], nums, dp);
            if(next > 0 || target - nums[idx] == 0) take = 1 + next;
        }
        return dp[idx][target] = max(take, notTake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        int ans = solve(n-1, target, nums, dp);
        return ans > 0 ? ans : -1;
    }
};