public class Solution {
    private int m, n;
    private readonly int[] dirs = { -1, 0, 1, 0, -1 };

    public int CountIslands(int[][] grid, int k) {
        m = grid.Length;
        n = grid[0].Length;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0 && Dfs(grid, i, j) % k == 0) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private long Dfs(int[][] grid, int i, int j) {
        long sum = grid[i][j];
        grid[i][j] = 0;
        for (int d = 0; d < 4; ++d) {
            int x = i + dirs[d], y = j + dirs[d + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0) {
                sum += Dfs(grid, x, y);
            }
        }
        return sum;
    }
}