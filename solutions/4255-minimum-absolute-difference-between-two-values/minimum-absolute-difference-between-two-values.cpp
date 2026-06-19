class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i] == 1 && nums[j] == 2) {
                    mini = min(mini, abs(i - j));
                }
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};