class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int cur = lower;

        for (int num : nums) {
            if (num < lower || num > upper) continue;

            if (cur < num) {
                res.push_back({cur, num - 1});
            }
            cur = max(cur, num + 1);

            if (cur > upper) break;
        }

        if (cur <= upper) {
            res.push_back({cur, upper});
        }

        return res;
    }
};