class Solution {
public:
    int dp[100002];
    bool func(int idx, vector<int>& nums)
    {
        if(idx==nums.size())
            return true;
        if(dp[idx]!=-1)
            return dp[idx];

        if(idx+1 < nums.size() && nums[idx+1]==nums[idx])
        {
            if(func(idx+2,nums))
                return dp[idx] = true;
        }
        if(idx+2 < nums.size() && nums[idx+1]==nums[idx] && nums[idx+2]==nums[idx])
        {
            if(func(idx+3,nums))
                return dp[idx] = true;
        }
        if(idx+2 < nums.size() && nums[idx+1]==nums[idx]+1 && nums[idx+2]==nums[idx]+2)
        {
            if(func(idx+3,nums))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return func(0,nums);
    }
};