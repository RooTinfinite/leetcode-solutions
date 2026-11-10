class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        vector<vector<int>> res;
        int cur = lower;
        for (int i = 0; i < nums.size() && nums[i] <= upper; i++) {
            if (nums[i] < lower)
                continue;
            if (cur < nums[i])
                res.push_back( { cur, nums[i] - 1 } );
            cur = nums[i] + 1;
        }
        if (cur <= upper)
            res.push_back( { cur, upper } );
        return res;
    }
};