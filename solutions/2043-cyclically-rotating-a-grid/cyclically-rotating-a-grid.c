int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k,
                 int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }

    int nlayer = fmin(m / 2, n / 2);  // level count
    // enumerate each layer counterclockwise starting from the top-left corner
    for (int layer = 0; layer < nlayer; ++layer) {
        int maxSize = 2 * (m + n - 4 * layer - 2);
        int* r = (int*)malloc(maxSize * sizeof(int));
        int* c = (int*)malloc(maxSize * sizeof(int));
        int* val = (int*)malloc(
            maxSize *
            sizeof(int));  // each element's row index, column index, and value
        int idx = 0;

        for (int i = layer; i < m - layer - 1; ++i) {  // left
            r[idx] = i;
            c[idx] = layer;
            val[idx] = grid[i][layer];
            idx++;
        }
        for (int j = layer; j < n - layer - 1; ++j) {  // down
            r[idx] = m - layer - 1;
            c[idx] = j;
            val[idx] = grid[m - layer - 1][j];
            idx++;
        }
        for (int i = m - layer - 1; i > layer; --i) {  // right
            r[idx] = i;
            c[idx] = n - layer - 1;
            val[idx] = grid[i][n - layer - 1];
            idx++;
        }
        for (int j = n - layer - 1; j > layer; --j) {  // up
            r[idx] = layer;
            c[idx] = j;
            val[idx] = grid[layer][j];
            idx++;
        }

        int total = idx;     // total number of elements in each layer
        int kk = k % total;  // equivalent number of rotations
        // find the value at each index after rotation
        for (int i = 0; i < total; ++i) {
            int pos =
                (i + total - kk) %
                total;  // the index corresponding to the value after rotation
            grid[r[i]][c[i]] = val[pos];
        }

        free(r);
        free(c);
        free(val);
    }
    return grid;
}