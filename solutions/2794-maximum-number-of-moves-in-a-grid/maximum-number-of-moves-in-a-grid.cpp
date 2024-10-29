class Solution {
public:
   int f(vector<vector<int>>& grid, int i, int j, int m, int n, int moves,vector<vector<int>> &dp) {
        if (j == n - 1)
            return moves;

        
        if (i < 0 || i >= m || j >= n)
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int dUp = 0;
        int front = 0;
        int dDown = 0;

        
        if (i - 1 >= 0 && j + 1 < n && grid[i - 1][j + 1] > grid[i][j]) {
            dUp = f(grid, i - 1, j + 1, m, n, moves + 1,dp);
        }

        if (j + 1 < n && grid[i][j + 1] > grid[i][j]) {
            front = f(grid, i, j + 1, m, n, moves + 1,dp);
        }

        if (i + 1 < m && j + 1 < n && grid[i + 1][j + 1] > grid[i][j]) {
            dDown = f(grid, i + 1, j + 1, m, n, moves + 1,dp);
        }

        return dp[i][j]=max({ dUp, front, dDown,moves});
    }

    int maxMoves(vector<vector<int>>& grid) {
        int maxiMoves = INT_MIN; 
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for (int i = 0; i < m; i++) {
            maxiMoves = max(maxiMoves, f(grid, i, 0, m, n, 0,dp));
        }

        return maxiMoves == INT_MIN ? 0 : maxiMoves; 
    }
};