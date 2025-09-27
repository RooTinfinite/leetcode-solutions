class Solution {
    public int getOperationCount(int[][] grid, int y, int notY) {
        int ans = 0;
        int n = grid.length;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i <= n / 2 && (i == j || i + j == n - 1)) || (i > n / 2 && j == n / 2)) {
                    if (y != grid[i][j]) ans++;
                } else {
                    if (notY != grid[i][j]) ans++;
                }
            }
        }
        
        return ans;
    }
    
    public int minimumOperationsToWriteY(int[][] grid) {
        int minOps = Integer.MAX_VALUE;
        int[][] combinations = {{0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 0}, {0, 2}};
        
        for (int[] comb : combinations) {
            int y = comb[0];
            int notY = comb[1];
            int res = getOperationCount(grid, y, notY);
            minOps = Math.min(minOps, res);
        }
        
        return minOps;
    }
}