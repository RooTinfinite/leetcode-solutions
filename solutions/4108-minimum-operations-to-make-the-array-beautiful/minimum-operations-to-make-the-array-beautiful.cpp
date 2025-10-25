class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<pair<int, int>, int> dp; // { {pos, prev_val}, val }
        return calculate(nums, 1, nums[0], dp);
    }

    int calculate(vector<int>& nums, int pos, int prev_val, map<pair<int, int>, int>& dp) {
        if (pos >= nums.size())
            return 0;
        if (dp.count( { pos, prev_val } ))
            return dp[ { pos, prev_val } ];
        int res = INT_MAX;
        for (int op = 0; nums[pos] + op <= 100; op++) {
            int cur_val = nums[pos] + op;
            if (cur_val % prev_val == 0)
                res = min(res, op + calculate(nums, pos + 1, cur_val, dp));
        }
        return dp[ { pos, prev_val } ] = res;
    }
};