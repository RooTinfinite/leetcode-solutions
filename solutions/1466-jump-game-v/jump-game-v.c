void dfs(int* arr, int id, int d, int n, int* f) {
    if (f[id] != -1) {
        return;
    }
    f[id] = 1;
    for (int i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
        dfs(arr, i, d, n, f);
        if (f[i] + 1 > f[id]) {
            f[id] = f[i] + 1;
        }
    }
    for (int i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
        dfs(arr, i, d, n, f);
        if (f[i] + 1 > f[id]) {
            f[id] = f[i] + 1;
        }
    }
}

int maxJumps(int* arr, int arrSize, int d) {
    int n = arrSize;
    int* f = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        f[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        dfs(arr, i, d, n, f);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (f[i] > ans) {
            ans = f[i];
        }
    }

    free(f);
    return ans;
}