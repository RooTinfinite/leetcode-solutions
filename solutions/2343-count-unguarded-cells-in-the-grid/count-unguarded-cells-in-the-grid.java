public class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        char[][] grid = new char[m][n];
        int unguarded = m * n;

        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = 'G';
            unguarded--;
        }

        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = 'W';
            unguarded--;
        }

        for (int[] guard : guards) {
            int row = guard[0], col = guard[1];

            for (int c = col + 1; c < n; c++) {
                if (grid[row][c] == 'G' || grid[row][c] == 'W') break;
                if (grid[row][c] != 'S') {
                    grid[row][c] = 'S';
                    unguarded--;
                }
            }

            for (int c = col - 1; c >= 0; c--) {
                if (grid[row][c] == 'G' || grid[row][c] == 'W') break;
                if (grid[row][c] != 'S') {
                    grid[row][c] = 'S';
                    unguarded--;
                }
            }

            for (int r = row + 1; r < m; r++) {
                if (grid[r][col] == 'G' || grid[r][col] == 'W') break;
                if (grid[r][col] != 'S') {
                    grid[r][col] = 'S';
                    unguarded--;
                }
            }

            for (int r = row - 1; r >= 0; r--) {
                if (grid[r][col] == 'G' || grid[r][col] == 'W') break;
                if (grid[r][col] != 'S') {
                    grid[r][col] = 'S';
                    unguarded--;
                }
            }
        }

        return unguarded;
    }
}