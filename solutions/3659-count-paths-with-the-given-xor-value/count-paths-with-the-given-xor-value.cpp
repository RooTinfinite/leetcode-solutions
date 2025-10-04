class Solution {
public:
    int mod = 1e9 + 7, k, n, m, dp[300][300][16];
    vector<vector<int>> grid;

    int f(int i, int j, int curr){
        if(i >= n || j >= m) return 0;
        curr ^= grid[i][j];  
        if(i == n - 1 && j == m - 1){
            return curr == k;
        }
        
        if (dp[i][j][curr] != -1) return dp[i][j][curr];
        int right = f(i, j + 1, curr) % mod;
        int down = f(i + 1, j, curr) % mod;
        return dp[i][j][curr] = (right + down) % mod;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        this->grid = grid;
        this->k = k;
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof dp);
        return f(0, 0, 0);
    }
};