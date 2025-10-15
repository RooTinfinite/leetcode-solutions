typedef long long ll;
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        ll ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n / 3; i++) {
            ans += nums[n - 2 - 2 * i];
        }
        return ans;
    }
};