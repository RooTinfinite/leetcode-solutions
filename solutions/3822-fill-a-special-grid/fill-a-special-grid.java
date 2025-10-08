public class Solution {
    public int[][] specialGrid(int N) {
        int size = 1 << N;
        int[][] grid = new int[size][size];
        for (int i = 0; i < N; i++) {
            for (int r = 0; r < size; r++) {
                for (int c = 0; c < size; c++) {
                    int temp = (r >> i) & 1;
                    int y    = (c >> i) & 1;
                    if (temp == 0) {
                        grid[r][c] += ((y == 0 ? 3 : 0) << (2 * i));
                    } else {
                        grid[r][c] += ((y == 0 ? 2 : 1) << (2 * i));
                    }
                }
            }
        }
        return grid;
    }
}