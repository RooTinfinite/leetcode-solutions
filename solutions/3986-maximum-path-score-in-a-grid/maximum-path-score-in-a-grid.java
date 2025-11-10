class Solution {
    public int maxPathScore(int[][] grid, int k) {
        int m = grid.length;
        int n =grid[0].length;
        int[][][] dp = new int[m][n][k+1];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                Arrays.fill(dp[i][j], Integer.MIN_VALUE);
        }
        
        int result = maxPathScore(0, 0, m, n, 0, k, grid, dp);
        return result < 0 ? -1 : result;
        
    }

    private int maxPathScore(int r, int c, int m, int n, int currK, int k, int[][] grid, int[][][] dp){
        if(r >= m || c >= n || currK > k)
            return -100000;

        if(r == m-1 && c == n-1){
            if(currK+getCost(grid[r][c]) <= k)
                return grid[r][c];
            else
                return -100000;
        }

        int newK = currK + getCost(grid[r][c]);
        if(newK > k)
            return -100000;

        if(dp[r][c][newK] != Integer.MIN_VALUE)
            return dp[r][c][newK];

        int takeRight = grid[r][c] + maxPathScore(r, c+1, m, n, newK, k, grid, dp);
        int takeDown = grid[r][c] + maxPathScore(r+1, c, m, n, newK, k, grid, dp);

        int result = Math.max(takeRight, takeDown);
        return dp[r][c][newK] = result;
    }

    private int getCost(int val){
        if(val == 0)
            return 0;

        else
            return 1;
    }
}