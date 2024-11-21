public class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        char[][] grid = new char[m][n];
        int unguarded = m * n;

        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = 1;
            unguarded--;
        }
        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = 2;
            unguarded--;
        }

        for (int[] guard : guards) {
            int row = guard[0], col = guard[1];

            for (int c = col + 1; c < n; c++) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                if (grid[row][c] == 0) {
                    grid[row][c] = 3;
                    unguarded--;
                }
            }

            for (int c = col - 1; c >= 0; c--) {
                if (grid[row][c] == 1 || grid[row][c] == 2) break;
                if (grid[row][c] == 0) {
                    grid[row][c] = 3;
                    unguarded--;
                }
            }

            for (int r = row + 1; r < m; r++) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                if (grid[r][col] == 0) {
                    grid[r][col] = 3;
                    unguarded--;
                }
            }

            for (int r = row - 1; r >= 0; r--) {
                if (grid[r][col] == 1 || grid[r][col] == 2) break;
                if (grid[r][col] == 0) {
                    grid[r][col] = 3;
                    unguarded--;
                }
            }
        }

        return unguarded;
    }
}