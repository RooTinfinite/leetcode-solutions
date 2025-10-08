class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> cuts = {0};
        for (int i = 1; i < n; ++i) if (nums[i] - nums[i - 1] > maxDiff) cuts.push_back(i);
        vector<bool> res;
        for (auto& q : queries)
            res.push_back(upper_bound(cuts.begin(), cuts.end(), q[0]) == upper_bound(cuts.begin(), cuts.end(), q[1]));
        return res;
    }
};