class Solution {
    
    private int[][] dp;

    public int minimumOperations(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[n][11];
        
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        
        for (int j = 0; j < 10; j++) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                sum += grid[i][0] != j ? 1 : 0;
            }
            dp[0][j] = sum;
        }
        
        for (int col = 1; col < n; col++) {
            for (int j = 0; j < 10; j++) {
                int sum = 0;
                for (int i = 0; i < m; i++) {
                    sum += grid[i][col] != j ? 1 : 0;
                }
                for (int k = 0; k < 10; k++) {
                    if (j != k) {
                        dp[col][j] = Math.min(dp[col][j], dp[col - 1][k] + sum);
                    }
                }
            }
        }
        
        int minOps = Integer.MAX_VALUE;
        for (int j = 0; j < 10; j++) {
            minOps = Math.min(minOps, dp[n - 1][j]);
        }
        
        return minOps;
    }
}