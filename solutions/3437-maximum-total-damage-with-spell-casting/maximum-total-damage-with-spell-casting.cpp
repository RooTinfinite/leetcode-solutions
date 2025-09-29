class Solution {
public:
    long long maximumTotalDamage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, long long>> dp;
        long long preMax = 0, ans = 0; int dpIdx = 0; 
        
        for(int i = 0; i < nums.size(); i++) {
            while(dpIdx < dp.size() && dp[dpIdx].first + 2 < nums[i]) {
                preMax = max(preMax, dp[dpIdx].second);
                dpIdx++;
            }
            
            int j = i; long long cur = 0;
            while(j < nums.size() && nums[j] == nums[i]) {
                cur += nums[j];
                j++;
            }
            
            ans = max(ans, cur + preMax);
            dp.push_back({nums[i], cur + preMax});
            i = j - 1;
        }
        return ans;
    }
};