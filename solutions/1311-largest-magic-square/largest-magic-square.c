int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    // prefix sum of each row
    int** rowsum = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        rowsum[i] = (int*)malloc(n * sizeof(int));
        rowsum[i][0] = grid[i][0];
        for (int j = 1; j < n; ++j) {
            rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
        }
    }
    // prefix sum of each column
    int** colsum = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        colsum[i] = (int*)malloc(n * sizeof(int));
    }
    for (int j = 0; j < n; ++j) {
        colsum[0][j] = grid[0][j];
        for (int i = 1; i < m; ++i) {
            colsum[i][j] = colsum[i - 1][j] + grid[i][j];
        }
    }

    int min_edge = m < n ? m : n;
    // enumerate edge lengths from largest to smallest
    for (int edge = min_edge; edge >= 2; --edge) {
        // enumerate the top-left corner position (i,j) of the square
        for (int i = 0; i + edge <= m; ++i) {
            for (int j = 0; j + edge <= n; ++j) {
                // calculate the standard value
                int stdsum =
                    rowsum[i][j + edge - 1] - (j > 0 ? rowsum[i][j - 1] : 0);
                int check = 1;
                // check each row
                for (int ii = i + 1; ii < i + edge; ++ii) {
                    int sum = rowsum[ii][j + edge - 1] -
                              (j > 0 ? rowsum[ii][j - 1] : 0);
                    if (sum != stdsum) {
                        check = 0;
                        break;
                    }
                }
                if (!check) continue;
                // check each column
                for (int jj = j; jj < j + edge; ++jj) {
                    int sum = colsum[i + edge - 1][jj] -
                              (i > 0 ? colsum[i - 1][jj] : 0);
                    if (sum != stdsum) {
                        check = 0;
                        break;
                    }
                }
                if (!check) continue;
                // check the diagonal
                int d1 = 0, d2 = 0;
                for (int k = 0; k < edge; ++k) {
                    d1 += grid[i + k][j + k];
                    d2 += grid[i + k][j + edge - 1 - k];
                }
                if (d1 == stdsum && d2 == stdsum) {
                    // release memory
                    for (int i = 0; i < m; ++i) {
                        free(rowsum[i]);
                        free(colsum[i]);
                    }
                    free(rowsum);
                    free(colsum);
                    return edge;
                }
            }
        }
    }

    // release memory
    for (int i = 0; i < m; ++i) {
        free(rowsum[i]);
        free(colsum[i]);
    }
    free(rowsum);
    free(colsum);

    return 1;
}