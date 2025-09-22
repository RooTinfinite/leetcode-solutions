class Solution {
    public boolean isValid(int[][] grid, int i, int j, int expectedValue, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != expectedValue) {
            return false;
        }

        if (expectedValue == n * n - 1) {
            return true;
        }

        boolean ans1 = isValid(grid, i - 2, j + 1, expectedValue + 1, n);
        boolean ans2 = isValid(grid, i - 1, j + 2, expectedValue + 1, n);
        boolean ans3 = isValid(grid, i + 1, j + 2, expectedValue + 1, n);
        boolean ans4 = isValid(grid, i + 2, j + 1, expectedValue + 1, n);
        boolean ans5 = isValid(grid, i + 2, j - 1, expectedValue + 1, n);
        boolean ans6 = isValid(grid, i + 1, j - 2, expectedValue + 1, n);
        boolean ans7 = isValid(grid, i - 1, j - 2, expectedValue + 1, n);
        boolean ans8 = isValid(grid, i - 2, j - 1, expectedValue + 1, n);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    public boolean checkValidGrid(int[][] grid) {
        return isValid(grid, 0, 0, 0, grid.length);
    }
}