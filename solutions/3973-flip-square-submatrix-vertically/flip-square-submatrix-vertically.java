
class Solution {
    public int[][] reverseSubmatrix(int[][] grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; i++) {
            int top = x + i;
            int bottom = x + k - 1 - i;
            for (int col = 0; col < k; col++) {
                int temp = grid[top][y + col];
                grid[top][y + col] = grid[bottom][y + col];
                grid[bottom][y + col] = temp;
            }
        }
        return grid;
    }
}
