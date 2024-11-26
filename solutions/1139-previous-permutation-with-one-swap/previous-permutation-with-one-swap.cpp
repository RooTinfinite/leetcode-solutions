class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& nums) {
        int n = nums.size(), i, j;
        // find the greater element from that adjacent element from the last
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1])
                break;
        }
        // if doesn't find element from the last that means nums is already
        // sorted
        if (i < 0)
            return nums;
        // find the smaller element from the last and swap them
        for (j = n - 1; j >= 1; j--) {
            if (nums[j] < nums[i] && nums[j] != nums[j - 1])
                break;
        }
        swap(nums[i], nums[j]);
        return nums;
    }
};