class Solution {
    private static final int[] DX = {-1, 0, 1, 0};
    private static final int[] DY = {0, 1, 0, -1};
    private static final int BLOCK_SHIFT = 6;
    private static final int BLOCK_MASK = 63;

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int blockRows = (m + BLOCK_MASK) >>> BLOCK_SHIFT;
        long[][] grid = new long[blockRows][n];
        long[][] guardedMask = new long[blockRows][n];

        int total = m * n;
        int guardedCount = guards.length + walls.length;

        for (int[] wall : walls) {
            setGridBit(grid, wall[0], wall[1]);
        }
        for (int[] guard : guards) {
            setGridBit(grid, guard[0], guard[1]);
        }

        for (int[] guard : guards) {
            for (int dir = 0; dir < 4; dir++) {
                int x = guard[0] + DX[dir];
                int y = guard[1] + DY[dir];

                while (x >= 0 && x < m && y >= 0 && y < n) {
                    int blockIdx = x >>> BLOCK_SHIFT;
                    long mask = 1L << (x & BLOCK_MASK);

                    if ((grid[blockIdx][y] & mask) != 0) {
                        break;
                    }

                    if ((guardedMask[blockIdx][y] & mask) == 0) {
                        guardedMask[blockIdx][y] |= mask;
                        guardedCount++;
                    }

                    x += DX[dir];
                    y += DY[dir];
                }
            }
        }

        return total - guardedCount;
    }

    private void setGridBit(long[][] grid, int row, int col) {
        grid[row >>> BLOCK_SHIFT][col] |= 1L << (row & BLOCK_MASK);
    }
}