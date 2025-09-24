class Solution {
public:
 
    // Memoization technique for solving but it doesnt get accepted IDK why
    int maxjumps(int index,vector<int>& nums,int target,vector<int>&dp){
        if(index==0){
            return 0;
        }
        int maxi=-1;
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i=1;i<nums.size();i++){
            if(index-i>=0){
            if(abs(nums[index]-nums[index-i])<=target){
                int jump=maxjumps(index-i,nums,target,dp)+1;
                if(jump!=0){
                    maxi=max(jump,maxi);
                }
                
                }
            }
            else{
                break;
            }
        }
        return dp[index]=maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        //return maxjumps(nums.size()-1,nums,target,dp);

        // Tabulisation technique which get accepted
        dp[0]=0;
        for(int i=1;i<nums.size();i++){
            int maxi=-1;
            for(int j=1;j<nums.size();j++){
                if(i-j>=0){
                    if(abs(nums[i]-nums[i-j])<=target){
                        int jump=dp[i-j]+1;
                        if(jump!=0){
                            maxi=max(jump,maxi);
                        }
                    }
                }
            }
            dp[i]=maxi;
        }
        return dp[nums.size()-1];
    }
};