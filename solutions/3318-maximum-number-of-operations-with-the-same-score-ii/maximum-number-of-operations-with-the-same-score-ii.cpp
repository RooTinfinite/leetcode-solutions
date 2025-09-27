class Solution {
public:
    vector<vector<int>> dp;

    int func(int l, int r, vector<int> &nums, int num){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        int ans = 0;
        if(nums[l]+nums[l+1] == num){
            ans = max(ans, 1+func(l+2, r, nums, num));
        }
        if(nums[r]+nums[r-1] == num){
            ans = max(ans, 1+func(l, r-2, nums, num));
        }
        if(nums[l]+nums[r] == num){
            ans = max(ans, 1+func(l+1, r-1, nums, num));
        }

        return dp[l][r] = ans;
    }

    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        int ans = 0;

        ans = max(ans, 1+func(2, n-1, nums, nums[0]+nums[1]));
        ans = max(ans, 1+func(0, n-3, nums, nums[n-1]+nums[n-2]));
        ans = max(ans, 1+func(1, n-2, nums, nums[0]+nums[n-1]));

        return ans;
    }
};