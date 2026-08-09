class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size(), n = grid[0].size();
        vector<bitset<250>> compat(n);
        for(auto& b : compat) { for (int k = 0; k < n; ++k) b[k] = 1; }

        vector<int> order(n), val(n);
        vector<bitset<250>> pref(n + 1);

        for(int i = 0; i < m; ++i) {
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](int a, int b){ return grid[i][a] < grid[i][b]; });
            for (int p = 0; p < n; ++p) val[p] = grid[i][order[p]];
            pref[0].reset();
            for(int p = 0; p < n; ++p) { pref[p + 1] = pref[p]; pref[p + 1][order[p]] = 1; }
            for(int j = 0; j < n; ++j) {
                int v = grid[i][j];
                int lo = lower_bound(val.begin(), val.end(), v - limit) - val.begin();
                int hi = upper_bound(val.begin(), val.end(), v + limit) - val.begin();
                compat[j] &= (pref[hi] ^ pref[lo]);
            }
        }

        vector<int> dp(n, 1);
        int ans = 1;
        for(int j = 0; j < n; ++j) {
            for (int k = compat[j]._Find_first(); k < j; k = compat[j]._Find_next(k))
                dp[j] = max(dp[j], dp[k] + 1);
            ans = max(ans, dp[j]);
        }
        return ans;
    }
};