class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        long[][] grid = new long[(m + 63) >>> 6][n];
        long[][] guardedMask = new long[(m + 63) >>> 6][n];

        int total = m * n;
        int guardedCount = guards.length + walls.length;

        for (int[] wall : walls) {
            int row = wall[0];
            int blockIdx = row >>> 6;
            grid[blockIdx][wall[1]] |= 1L << (row & 63);
        }

        for (int[] guard : guards) {
            int row = guard[0];
            int blockIdx = row >>> 6;
            grid[blockIdx][guard[1]] |= 1L << (row & 63);
        }

        final int[] dx = {-1, 0, 1, 0};
        final int[] dy = {0, 1, 0, -1};

        for (int[] guard : guards) {
            int x0 = guard[0], y0 = guard[1];
            for (int dir = 0; dir < 4; dir++) {
                int x = x0 + dx[dir];
                int y = y0 + dy[dir];
                while (x >= 0 && x < m && y >= 0 && y < n) {
                    int blockIdx = x >>> 6;
                    long mask = 1L << (x & 63);
                    if ((grid[blockIdx][y] & mask) != 0) break;
                    if ((guardedMask[blockIdx][y] & mask) == 0) {
                        guardedMask[blockIdx][y] |= mask;
                        guardedCount++;
                    }
                    x += dx[dir];
                    y += dy[dir];
                }
            }
        }

        return total - guardedCount;
    }
}