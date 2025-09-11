class Solution {
public:
int ans=INT_MAX;
    void helper(int start, vector<int>& nums, vector<int>& tc, int k){
        //bc
        if(start==nums.size()){
            int temp=INT_MIN;
            for(int i=0;i<k;i++){
                temp=max(temp,tc[i]);
            }
            ans=min(ans,temp);
            return;
        }

        for(int i=0;i<k;i++){
            tc[i]+=nums[start];
            helper(start+1,nums,tc,k);
            tc[i]-=nums[start];
        }
        
    }
    
    int distributeCookies(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tc(k,0); 
        helper(0,nums,tc,k);
        return ans;
    }
};