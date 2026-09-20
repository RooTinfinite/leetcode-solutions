class Solution {
    public int[][] cyclicShift(int n, int[][] grid, int[] rowShift, int[] colShift) {
        int[][] result = new int[n][n];
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++) {
                int nc = (c - rowShift[r] % n + n) % n;
                int nr = (r - colShift[nc] % n + n) % n;
                result[nr][nc] = grid[r][c];
            }
        return result;
    }
}