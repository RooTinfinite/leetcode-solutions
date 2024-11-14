long long sum[100005];
int last[100005];

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        memset(last, -1 , sizeof(last));
        
        int left=-1;
        long long mx=0;
        for(int i=0; i<nums.size(); i++)
        {
            int len ;
            left = max(left, last[nums[i]]); /// updating left index because unique element we need
          
            last[nums[i]]=i; /// storing lastest index of this element
            len = i - left;  /// max unique elements subarray length
            sum[i+1] = sum[i]+nums[i]; /// prefix sum
            if(len >= k) mx = max(mx , sum[i+1]-sum[i+1-k]);
        }
        
        return mx;
    }
};