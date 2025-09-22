class Solution {
    public boolean isPossibleToCutPath(int[][] grid) {
        // check if path exists
        if (!isReachable(grid, 0, 0)) {
            return true;    // if not, return true
        }

        // we have set the first path that the DFS travelled to all 0s
        grid[0][0] = 1; // starting point needs to be a 1
        // check if any more paths exists or not
        if (!isReachable(grid, 0, 0)) {
            return true;    // if not, return true
        }
        
        // otherwise we have learned, 1 flip isn't sufficient
        // so matrix can't be disconnected
        return false;
    }

    private boolean isReachable(int[][] grid, int i, int j) {
        // end point is last cell of last row and column
        if (i == grid.length - 1 && j == grid[0].length - 1) {
            return true;    // reached the end point, return true
        }
        // moved out of bounds, or encountered a 0 means path is blocked
        if (i >= grid.length || j >= grid[0].length || grid[i][j] == 0) {
            return false;   // con't move so return false
        }
        grid[i][j] = 0; // block the path
        // move down, move right, Either or both can reach the end point
        return isReachable(grid, i + 1, j) || isReachable(grid, i, j + 1);
    }
}