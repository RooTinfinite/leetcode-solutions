public class Solution {
    private static final int[] DIRECTIONS_ROW = {-1, 1, 0, 0};
    private static final int[] DIRECTIONS_COL = {0, 0, -1, 1};

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        char[][] grid = new char[m][n];
        int unguarded = m * n - guards.length - walls.length;

        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = 'G';
        }
        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = 'W';
        }

        for (int[] guard : guards) {
            for (int dir = 0; dir < 4; dir++) {
                int row = guard[0] + DIRECTIONS_ROW[dir];
                int col = guard[1] + DIRECTIONS_COL[dir];

                while (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] != 'W' && grid[row][col] != 'G') {
                    if (grid[row][col] != 'S') {
                        grid[row][col] = 'S';
                        unguarded--;
                    }
                    row += DIRECTIONS_ROW[dir];
                    col += DIRECTIONS_COL[dir];
                }
            }
        }

        return unguarded;
    }
}