class Solution {
    int mod = 1_000_000_007;
    int[][] grid;
    int k, n, m;
    int[][][] dp;

    public int f(int i, int j, int curr) {
        if (i >= n || j >= m) return 0;
        
        curr ^= grid[i][j];
        
        if (i == n - 1 && j == m - 1) {
            return curr == k ? 1 : 0;
        }
        
        if (dp[i][j][curr] != -1) return dp[i][j][curr];
        
        int right = f(i, j + 1, curr) % mod;
        int down = f(i + 1, j, curr) % mod;
        
        dp[i][j][curr] = (right + down) % mod;
        return dp[i][j][curr];
    }

    public int countPathsWithXorValue(int[][] grid, int k) {
        this.grid = grid;
        this.k = k;
        n = grid.length;
        m = grid[0].length;
        
        dp = new int[n][m][20];
        for (int[][] layer : dp) {
            for (int[] row : layer) {
                java.util.Arrays.fill(row, -1);
            }
        }
        
        return f(0, 0, 0);
    }
}