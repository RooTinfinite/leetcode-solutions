class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = -1e9;
        
        // 1. Check all strictly interior single cells
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                ans = max(ans, grid[i][j]);
            }
        }

        // 2. Modified Kadane's for Rows (Minimum length 2)
        for(int i = 0; i < n; i++) {
            int mx = -1e9, sum = grid[i][0];
            for(int j = 1; j < m; j++) {
                mx = max(mx, sum + grid[i][j]);          // Force length >= 2
                sum = max(grid[i][j], sum + grid[i][j]); // Standard Kadane update
            }
            ans = max(ans, mx);
        }
        
        // 3. Modified Kadane's for Columns (Minimum length 2)
        for(int j = 0; j < m; j++) {
            int mx = -1e9, sum = grid[0][j];
            for(int i = 1; i < n; i++) {
                mx = max(mx, sum + grid[i][j]);          // Force length >= 2
                sum = max(grid[i][j], sum + grid[i][j]); // Standard Kadane update
            }
            ans = max(ans, mx);
        }

        return ans;
    }
};