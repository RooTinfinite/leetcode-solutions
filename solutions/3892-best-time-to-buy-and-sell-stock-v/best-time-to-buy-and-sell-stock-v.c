long long dfs(long long*** memo, int* prices, int n, int i, int j, int state) {
    if (j == 0) {
        return 0;
    }
    if (i == 0) {
        return state == 0 ? 0 : (state == 1 ? -prices[0] : prices[0]);
    }
    if (memo[i][j][state] != -1) {
        return memo[i][j][state];
    }
    int p = prices[i];
    long long res;
    if (state == 0) {
        long long a = dfs(memo, prices, n, i - 1, j, 0);
        long long b = dfs(memo, prices, n, i - 1, j, 1) + p;
        long long c = dfs(memo, prices, n, i - 1, j, 2) - p;
        res = fmax(a, fmax(b, c));
    } else if (state == 1) {
        long long a = dfs(memo, prices, n, i - 1, j, 1);
        long long b = dfs(memo, prices, n, i - 1, j - 1, 0) - p;
        res = fmax(a, b);
    } else {
        long long a = dfs(memo, prices, n, i - 1, j, 2);
        long long b = dfs(memo, prices, n, i - 1, j - 1, 0) + p;
        res = fmax(a, b);
    }
    memo[i][j][state] = res;
    return res;
}

long long maximumProfit(int* prices, int pricesSize, int k) {
    long long*** memo = (long long***)malloc(sizeof(long long**) * pricesSize);
    for (int i = 0; i < pricesSize; i++) {
        memo[i] = (long long**)malloc(sizeof(long long*) * (k + 1));
        for (int j = 0; j <= k; j++) {
            memo[i][j] = (long long*)malloc(sizeof(long long) * 3);
            memset(memo[i][j], -1, sizeof(long long) * 3);
        }
    }

    long long ret = dfs(memo, prices, pricesSize, pricesSize - 1, k, 0);
    for (int i = 0; i < pricesSize; i++) {
        for (int j = 0; j <= k; j++) {
            free(memo[i][j]);
        }
        free(memo[i]);
    }

    return ret;
}