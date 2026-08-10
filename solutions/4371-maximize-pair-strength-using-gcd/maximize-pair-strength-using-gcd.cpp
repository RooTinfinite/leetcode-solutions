class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long l = gcd(nums[i],nums[j]);
                long long k = (1LL*nums[i]*nums[j])/(1LL*l*l);

                ans = max(ans,k);
            }
        }

        return ans;
    }
};