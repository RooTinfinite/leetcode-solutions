class Solution {
    int n, m;

    public int dfs(int i, int j, int xori, int[][] grid, int[][][] dp) {
        if (i >= n || j >= m) return Integer.MAX_VALUE;

        xori ^= grid[i][j];

        if (i == n - 1 && j == m - 1) {
            return xori;
        }

        if (dp[i][j][xori] != -1) return dp[i][j][xori];

        int right = dfs(i, j + 1, xori, grid, dp);
        int down = dfs(i + 1, j, xori, grid, dp);

        return dp[i][j][xori] = Math.min(right, down);
    }

    public int minCost(int[][] grid) {
        n = grid.length;
        m = grid[0].length;

        int[][][] dp = new int[n][m][1024];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        return dfs(0, 0, 0, grid, dp);
    }
}