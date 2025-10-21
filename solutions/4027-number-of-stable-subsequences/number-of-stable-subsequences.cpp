class Solution {
    int dp[100001][3][3];
    const int mod = 1e9+7;
    int solve(vector<int>&nums,int i,int parity,int count){
        if(i == nums.size()){
            if(parity == -1) return 0;
            return 1;
        }
        if(dp[i][parity+1][count] != -1) return dp[i][parity+1][count];
        //choosing curr element
        int curr = nums[i]%2;
        int ans = 0;
        //same parity
        if(curr == parity && count < 2){
           ans = (ans+solve(nums,i+1,curr,count+1))%mod;
        }
        //different parity
        else if(curr != parity){
            ans = (ans+solve(nums,i+1,curr,1))%mod;
        }
        //not choosing curr element
        ans = (ans+solve(nums,i+1,parity,count))%mod;
        return dp[i][parity+1][count] = ans;
    }
public:
    int countStableSubsequences(vector<int>& nums){
        memset(dp,-1,sizeof(dp));
       return solve(nums,0,-1,0);
    }
};