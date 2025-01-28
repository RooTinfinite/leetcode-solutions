#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<ll, ll> m;
        ll ans = -1e15;
        ll prefix_sum = 0;
        for(int i=0; i<n; i++){
            //store min possible prefix sum for nums[i]
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = prefix_sum;
            }
            else{
                m[nums[i]] = min(prefix_sum, m[nums[i]]);
            }
            prefix_sum += nums[i];
            //check for nums[i] - k
            if(m.find(nums[i] - k) != m.end()){
                ans = max(ans, prefix_sum - m[nums[i] - k]);
            }
            //check for nums[i] + k
            if(m.find(nums[i] + k) != m.end()){
                ans = max(ans, prefix_sum - m[nums[i] + k]);
            }
        }
        if(ans == -1e15) return 0; // no good suarray exists
        return ans;
    }
};