class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        long long int ans=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ans)
            {
                ans*=2;
            }
        }
        return ans;
    }
};