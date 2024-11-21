class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];

        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = -1;
        }

        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = -2;
        }

        for (int[] guard : guards) {
            int x = guard[0], y = guard[1];

            for (int i = x - 1; i >= 0 && grid[i][y] >= -1; i--) {
                if (grid[i][y] == -1) break;
                grid[i][y] = 1;
            }

            for (int i = x + 1; i < m && grid[i][y] >= -1; i++) {
                if (grid[i][y] == -1) break;
                grid[i][y] = 1;
            }

            for (int j = y - 1; j >= 0 && grid[x][j] >= -1; j--) {
                if (grid[x][j] == -1) break;
                grid[x][j] = 1;
            }

            for (int j = y + 1; j < n && grid[x][j] >= -1; j++) {
                if (grid[x][j] == -1) break;
                grid[x][j] = 1;
            }
        }

        int unguarded = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unguarded++;
                }
            }
        }

        return unguarded;
    }
}