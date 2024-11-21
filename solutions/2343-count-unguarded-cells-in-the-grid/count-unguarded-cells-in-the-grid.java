class Solution {
    private static final int[] DX = {-1, 0, 1, 0};
    private static final int[] DY = {0, 1, 0, -1};
    private static final int BITS_PER_WORD = 64;
    private static final int BLOCK_SHIFT = 6;
    private static final int BLOCK_MASK = 63;

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {

        int blockRows = (m + BLOCK_MASK) >>> BLOCK_SHIFT;
        long[][] grid = new long[blockRows][n];
        long[][] guardedMask = new long[blockRows][n];

        int guardedCount = initializeGridAndCount(m, n, guards, walls, grid);
        guardedCount = processGuardVision(m, n, guards, grid, guardedMask, guardedCount);

        return m * n - guardedCount;
    }

    private int initializeGridAndCount(int m, int n, int[][] guards, int[][] walls, long[][] grid) {
        int count = 0;
        for (int[] wall : walls) {
            setGridBit(grid, wall[0], wall[1]);
            count++;
        }
        for (int[] guard : guards) {
            setGridBit(grid, guard[0], guard[1]);
            count++;
        }
        return count;
    }

    private int processGuardVision(int m, int n, int[][] guards, long[][] grid, long[][] guardedMask, int guardedCount) {
        for (int[] guard : guards) {
            for (int dir = 0; dir < 4; dir++) {
                guardedCount = processDirection(m, n, guard[0], guard[1], dir, grid, guardedMask, guardedCount);
            }
        }
        return guardedCount;
    }

    private int processDirection(int m, int n, int startX, int startY, int dir, long[][] grid, long[][] guardedMask, int guardedCount) {
        int x = startX + DX[dir];
        int y = startY + DY[dir];

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
        return guardedCount;
    }

    private void setGridBit(long[][] grid, int row, int col) {
        grid[row >>> BLOCK_SHIFT][col] |= 1L << (row & BLOCK_MASK);
    }
}