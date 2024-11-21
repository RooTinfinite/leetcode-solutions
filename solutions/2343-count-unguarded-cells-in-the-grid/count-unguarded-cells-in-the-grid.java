class Solution {
    private static final int[] DX = {-1, 0, 1, 0};
    private static final int[] DY = {0, 1, 0, -1};
    private static final int BLOCK_SHIFT = 6;
    private static final int BLOCK_MASK = 63;
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int blocks = (m + BLOCK_MASK) >>> BLOCK_SHIFT;
        long[][] grid = new long[blocks][n];
        long[][] guardedMask = new long[blocks][n];
        int totalCells = m * n;
        int guardedCount = guards.length + walls.length;
        for (int[] wall : walls) {
            setBit(grid, wall[0], wall[1]);
        }
        for (int[] guard : guards) {
            setBit(grid, guard[0], guard[1]);
        }
        for (int[] guard : guards) {
            int x0 = guard[0], y0 = guard[1];
            for (int dir = 0; dir < 4; dir++) {
                int x = x0 + DX[dir];
                int y = y0 + DY[dir];
                while (isValid(x, y, m, n)) {
                    int blockIdx = x >>> BLOCK_SHIFT;
                    long mask = 1L << (x & BLOCK_MASK);
                    if ((grid[blockIdx][y] & mask) != 0) break;
                    if ((guardedMask[blockIdx][y] & mask) == 0) {
                        guardedMask[blockIdx][y] |= mask;
                        guardedCount++;
                    }
                    x += DX[dir];
                    y += DY[dir];
                }
            }
        }
        return totalCells - guardedCount;
    }
    private static void setBit(long[][] grid, int row, int col) {
        grid[row >>> BLOCK_SHIFT][col] |= 1L << (row & BLOCK_MASK);
    }
    private static boolean isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}