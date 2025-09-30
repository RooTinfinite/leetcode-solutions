class Solution {
    public int numberOfSubmatrices(char[][] grid) {
        int m = grid.length, n = grid[0].length, result = 0;
        int[][][] dp = new int[m + 1][n + 1][2];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j][0] = dp[i-1][j][0] + dp[i][j-1][0] - dp[i-1][j-1][0] + (grid[i-1][j-1] == 'X' ? 1 : 0);
                dp[i][j][1] = dp[i-1][j][1] + dp[i][j-1][1] - dp[i-1][j-1][1] + (grid[i-1][j-1] == 'Y' ? 1 : 0);
                if (dp[i][j][0] != 0 && dp[i][j][0] == dp[i][j][1])
                    result++;
            }
        }
        return result;
    }
}