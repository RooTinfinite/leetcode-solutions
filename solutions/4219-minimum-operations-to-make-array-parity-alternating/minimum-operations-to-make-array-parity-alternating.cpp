class Solution {
    static pair<int, int> solve(const vector<int>& nums, int start_parity) {
        int n = nums.size();
        int ops = 0;

        vector<pair<int,int>> points; // (value, index_id)
        points.reserve(2 * n);

        for (int i = 0; i < n; ++i) {
            if ((nums[i] & 1) == (start_parity ^ (i & 1))) {
                points.push_back({nums[i], i});
            } else {
                ops += 1;
                points.push_back({nums[i] - 1, i});
                points.push_back({nums[i] + 1, i});
            }
        }

        sort(points.begin(), points.end());

        // Minimal range that contains at least one option for each i
        vector<int> cnt(n, 0);
        int best_range = INT_MAX;
        int covered = 0, l = 0;

        for (int r = 0; r < points.size(); ++r) {
            int vr = points[r].first;
            int ir = points[r].second;

            if (cnt[ir] == 0) covered++;
            cnt[ir]++;

            // If all elements are covered try to find best range
            while (covered == n) {
                int vl = points[l].first;
                int il = points[l].second;

                best_range = min(best_range, vr - vl);

                cnt[il]--;
                if (cnt[il] == 0) covered--;
                l++;
            }
        }

        return {ops, best_range};
    }

public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) 
            return {0, 0};

        auto a = solve(nums, 0);
        auto b = solve(nums, 1);
        auto ans = (a < b ? a : b);  // min by (ops, range)
        return {ans.first, ans.second};
    }
};