int stoneGameV(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;
    int** f = (int**)malloc(sizeof(int*) * n);
    int** maxl = (int**)malloc(sizeof(int*) * n);
    int** maxr = (int**)malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++) {
        f[i] = (int*)calloc(n, sizeof(int));
        maxl[i] = (int*)calloc(n, sizeof(int));
        maxr[i] = (int*)calloc(n, sizeof(int));
    }

    for (int left = n - 1; left >= 0; left--) {
        maxl[left][left] = stoneValue[left];
        maxr[left][left] = stoneValue[left];
        int total = stoneValue[left];
        int suml = 0;
        int i = left - 1;
        for (int right = left + 1; right < n; right++) {
            total += stoneValue[right];
            while (i + 1 < right && (suml + stoneValue[i + 1]) * 2 <= total) {
                suml += stoneValue[i + 1];
                i++;
            }
            if (left <= i) {
                f[left][right] = fmax(f[left][right], maxl[left][i]);
            }
            if (i + 1 < right) {
                f[left][right] = fmax(f[left][right], maxr[i + 2][right]);
            }
            if (suml * 2 == total) {
                f[left][right] = fmax(f[left][right], maxr[i + 1][right]);
            }
            maxl[left][right] =
                fmax(maxl[left][right - 1], total + f[left][right]);
            maxr[left][right] =
                fmax(maxr[left + 1][right], total + f[left][right]);
        }
    }

    int result = f[0][n - 1];

    for (int i = 0; i < n; i++) {
        free(f[i]);
        free(maxl[i]);
        free(maxr[i]);
    }
    free(f);
    free(maxl);
    free(maxr);

    return result;
}