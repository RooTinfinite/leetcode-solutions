

class Solution {
public:
    long long maximumTotalSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = nums.back();
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] >= nums[i + 1]) {
                nums[i] = nums[i + 1] - 1;
                ans += nums[i];
                if (nums[i] <= 0) {
                    return -1;
                }
            } else {
                ans += nums[i];
            }
        }
        
        return ans;
    }
};