class Solution {
    public int maximumAmount(int[][] coins) {
        int m = coins.length, n = coins[0].length; 
        int[][][] dp = new int[m][n][4]; 
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                Arrays.fill(dp[i][j], -1_000_000_000); 
        dp[0][0][2] = coins[0][0]; 
        if (coins[0][0] < 0) dp[0][0][1] = 0; 
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                for (int k = 0; k <= 2; ++k) {

                    if (i > 0) dp[i][j][k] = Math.max(dp[i][j][k], Math.max(dp[i-1][j][k] + coins[i][j], dp[i-1][j][k+1])); 
                    if (j > 0) dp[i][j][k] = Math.max(dp[i][j][k], Math.max(dp[i][j-1][k] + coins[i][j], dp[i][j-1][k+1])); 
                }
        return Math.max(dp[m-1][n-1][0], Math.max(dp[m-1][n-1][1], dp[m-1][n-1][2])); 
    }
}