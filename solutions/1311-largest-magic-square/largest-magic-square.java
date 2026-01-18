class Solution {

    public int largestMagicSquare(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        // prefix sum of each row
        int[][] rowsum = new int[m][n];
        for (int i = 0; i < m; ++i) {
            rowsum[i][0] = grid[i][0];
            for (int j = 1; j < n; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
            }
        }
        // prefix sum of each column
        int[][] colsum = new int[m][n];
        for (int j = 0; j < n; ++j) {
            colsum[0][j] = grid[0][j];
            for (int i = 1; i < m; ++i) {
                colsum[i][j] = colsum[i - 1][j] + grid[i][j];
            }
        }

        // enumerate edge lengths from largest to smallest
        for (int edge = Math.min(m, n); edge >= 2; --edge) {
            // enumerate the top-left corner position (i,j) of the square
            for (int i = 0; i + edge <= m; ++i) {
                for (int j = 0; j + edge <= n; ++j) {
                    // the value for each row, column, and diagonal should be calculated (using the first row as a sample)
                    int stdsum =
                        rowsum[i][j + edge - 1] -
                        (j > 0 ? rowsum[i][j - 1] : 0);
                    boolean check = true;
                    // enumerate each row and directly compute the sum using prefix sums
                    for (int ii = i + 1; ii < i + edge; ++ii) {
                        if (
                            rowsum[ii][j + edge - 1] -
                                (j > 0 ? rowsum[ii][j - 1] : 0) !=
                            stdsum
                        ) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) continue;
                    // enumerate each column and directly calculate the sum using prefix sums
                    for (int jj = j; jj < j + edge; ++jj) {
                        if (
                            colsum[i + edge - 1][jj] -
                                (i > 0 ? colsum[i - 1][jj] : 0) !=
                            stdsum
                        ) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) continue;
                    // 两条对角线的和
                    int d1 = 0;
                    int d2 = 0;
                    for (int k = 0; k < edge; ++k) {
                        d1 += grid[i + k][j + k];
                        d2 += grid[i + k][j + edge - 1 - k];
                    }
                    if (d1 == stdsum && d2 == stdsum) {
                        return edge;
                    }
                }
            }
        }
        return 1;
    }
}