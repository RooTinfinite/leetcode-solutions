class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long ans=0;
        int ct=min(k,mul-1);
        k = k-ct;
        int i=0;
        while(ct--){
            ans+=(1LL*nums[i]*mul);
            i++;
            mul--;
        }
        while(k>0){
            ans+=nums[i];
            i++;
            k--;
        }
        return ans;
    } 
};