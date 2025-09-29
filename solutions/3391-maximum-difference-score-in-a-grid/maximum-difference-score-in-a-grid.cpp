class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i >= grid.size() || j >= grid[0].size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int pick1 = INT_MIN, pick2 = INT_MIN;
        if (i + 1 < grid.size()) pick1 = grid[i + 1][j] - grid[i][j] + solve(i + 1, j, grid, dp);
        if (j + 1 < grid[0].size()) pick2 = grid[i][j + 1] - grid[i][j] + solve(i, j + 1, grid, dp);

        dp[i][j] = max(0, max(pick1, pick2));
        return dp[i][j];
    }

    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxi = INT_MIN;
        int maxi1 = INT_MIN;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                maxi = max(maxi, solve(i, j, grid, dp));
                if(i+1 < m) maxi1 = max(maxi1, grid[i+1][j] - grid[i][j]);
                if(j+1 < n) maxi1 = max(maxi1, grid[i][j+1] - grid[i][j]);
            }
        }
        if(maxi == 0) return maxi1;
        return maxi;
    }
};