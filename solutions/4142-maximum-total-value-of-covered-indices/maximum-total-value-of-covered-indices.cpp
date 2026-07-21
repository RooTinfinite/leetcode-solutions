class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans = 0;
        long long mini = INT_MAX;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                // current value can be covered
                ans += nums[i];
                // smallest value in current block
                mini = min(mini, (long long)nums[i]);
            } else {
                // a token from i+1 can move here
                if(i + 1 < n && s[i + 1] == '1') {
                    ans += nums[i];
                    // one position must stay uncovered,
                    // remove the smallest value
                    mini = min(mini, (long long)nums[i]);
                    ans -= mini;
                }
                // start a new block
                mini = INT_MAX;
            }
        }
        return ans;
    }
};