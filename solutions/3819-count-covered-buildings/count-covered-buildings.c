int countCoveredBuildings(int n, int** buildings, int buildingsSize,
                          int* buildingsColSize) {
    int* maxRow = (int*)calloc(n + 1, sizeof(int));
    int* minRow = (int*)malloc((n + 1) * sizeof(int));
    int* maxCol = (int*)calloc(n + 1, sizeof(int));
    int* minCol = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        minRow[i] = n + 1;
        minCol[i] = n + 1;
    }

    for (int i = 0; i < buildingsSize; i++) {
        int x = buildings[i][0];
        int y = buildings[i][1];
        maxRow[y] = fmax(maxRow[y], x);
        minRow[y] = fmin(minRow[y], x);
        maxCol[x] = fmax(maxCol[x], y);
        minCol[x] = fmin(minCol[x], y);
    }

    int res = 0;
    for (int i = 0; i < buildingsSize; i++) {
        int x = buildings[i][0];
        int y = buildings[i][1];
        if (x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x]) {
            res++;
        }
    }

    free(maxRow);
    free(minRow);
    free(maxCol);
    free(minCol);

    return res;
}