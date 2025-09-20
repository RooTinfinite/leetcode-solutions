class Solution {
public:
    typedef long long ll;
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        ll sum=0,maxAvg=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            ll currAvg=ceil((double)sum/(i+1));
            maxAvg=max(currAvg,maxAvg);
        }
        return maxAvg;
    }
};