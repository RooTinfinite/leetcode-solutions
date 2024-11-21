class Solution {
    private static final int BLOCK_SHIFT = 6;
    private static final int BLOCK_MASK = 63;
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        final int blockRows = (m + BLOCK_MASK) >>> BLOCK_SHIFT;
        final int total = m * n;
        final long[][] grid = new long[blockRows][n];
        final long[][] guardedMask = new long[blockRows][n];
        int guardedCount = processObstacles(guards, walls, grid, blockRows);
        guardedCount = processGuardVision(m, n, guards, grid, guardedMask, guardedCount);
        return total - guardedCount;
    }
    private static int processObstacles(int[][] guards, int[][] walls, long[][] grid, int blockRows) {
        int count = guards.length + walls.length;
        for (int[] wall : walls) {
            setBit(grid, wall[0], wall[1]);
        }
        for (int[] guard : guards) {
            setBit(grid, guard[0], guard[1]);
        }
        return count;
    }
    private static void setBit(long[][] grid, int row, int col) {
        grid[row >>> BLOCK_SHIFT][col] |= 1L << (row & BLOCK_MASK);
    }
    private static int processGuardVision(int m, int n, int[][] guards, long[][] grid, long[][] guardedMask, int guardedCount) {
        final int[] dx = {-1, 1, 0, 0};
        final int[] dy = {0, 0, -1, 1};
        for (int[] guard : guards) {
            final int x0 = guard[0], y0 = guard[1];
            for (int dir = 0; dir < 4; dir++) {
                guardedCount = scanLine(m, n, x0, y0, dx[dir], dy[dir], grid, guardedMask, guardedCount);
            }
        }
        return guardedCount;
    }
    private static int scanLine(int m, int n, int x0, int y0, int dx, int dy, long[][] grid, long[][] guardedMask, int count) {
        int x = x0 + dx;
        int y = y0 + dy;
        
        while (x >= 0 && x < m && y >= 0 && y < n) {
            final int blockIdx = x >>> BLOCK_SHIFT;
            final long mask = 1L << (x & BLOCK_MASK);
            if ((grid[blockIdx][y] & mask) != 0) break;
            if ((guardedMask[blockIdx][y] & mask) == 0) {
                guardedMask[blockIdx][y] |= mask;
                count++;
            }
            x += dx;
            y += dy;
        }
        return count;
    }
}