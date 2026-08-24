int stoneGameVIII(int* stones, int stonesSize) {
    int n = stonesSize;
    int* pre = (int*)malloc(n * sizeof(int));
    pre[0] = stones[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + stones[i];
    }

    int* f = (int*)malloc(n * sizeof(int));
    f[n - 1] = pre[n - 1];
    for (int i = n - 2; i >= 1; i--) {
        f[i] = f[i + 1] > (pre[i] - f[i + 1]) ? f[i + 1] : (pre[i] - f[i + 1]);
    }

    int result = f[1];
    free(pre);
    free(f);
    return result;
}