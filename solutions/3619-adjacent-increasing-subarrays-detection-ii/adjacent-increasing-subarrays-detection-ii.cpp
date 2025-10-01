class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev_increase = 0, cur_increase = 1;
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                cur_increase += 1;
            } else {
                prev_increase = cur_increase;
                cur_increase = 1;
            }
            res = max(res, max(cur_increase / 2, min(prev_increase, cur_increase))); 
        }
        return res;
    }
};