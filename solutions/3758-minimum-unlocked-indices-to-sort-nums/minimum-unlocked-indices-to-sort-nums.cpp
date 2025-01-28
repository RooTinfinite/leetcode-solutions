class Solution {
public:
    int minUnlockedIndices(vector<int>& nums, vector<int>& locked) {
        int cur_max = 1, locks = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cur_max < nums[i]) {
                cur_max = nums[i];
                locks = 0;
            }
            if (nums[i] < cur_max) {
                if (nums[i] + 1 < cur_max)
                    return -1;                
                res += locks;
                locks = 0;
            }
            locks += locked[i];
        }
        return res;
    }
};