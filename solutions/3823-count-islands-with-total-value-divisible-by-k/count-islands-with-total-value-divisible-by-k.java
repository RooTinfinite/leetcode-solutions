public class Solution {

    private void helpIslands(int[][] grid, int i, int j, int m, int n, long[] sum) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }

        sum[0] += grid[i][j];
        grid[i][j] = 0;

        helpIslands(grid, i - 1, j, m, n, sum);
        helpIslands(grid, i + 1, j, m, n, sum);
        helpIslands(grid, i, j - 1, m, n, sum);
        helpIslands(grid, i, j + 1, m, n, sum);
    }

    public int countIslands(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long[] sum = new long[1];
                    helpIslands(grid, i, j, m, n, sum);
                    if (sum[0] % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
}