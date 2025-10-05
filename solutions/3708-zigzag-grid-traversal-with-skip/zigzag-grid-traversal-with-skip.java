class Solution {
    public List<Integer> zigzagTraversal(int[][] grid) {
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < grid.length; i++) {
            if (i % 2 != 0) {

                for (int left = 0, right = grid[i].length - 1; left < right; left++, right--) {
                    int temp = grid[i][left];
                    grid[i][left] = grid[i][right];
                    grid[i][right] = temp;  } } }

        boolean take = true;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (take) {
                    result.add(grid[i][j]);}
                take = !take; } }

        return result; } }