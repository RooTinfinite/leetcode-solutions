int dfs(int** coins, int*** memo, int m, int n, int i, int j, int k) {
    if (i < 0 || j < 0) {
        return INT_MIN;
    }

    int x = coins[i][j];
    if (i == 0 && j == 0) {
        return k > 0 ? (x > 0 ? x : 0) : x;
    }
    if (memo[i][j][k] != INT_MIN) {
        return memo[i][j][k];
    }

    int res = fmax(dfs(coins, memo, m, n, i - 1, j, k),
                   dfs(coins, memo, m, n, i, j - 1, k)) +
              x;

    if (k > 0 && x < 0) {
        res = fmax(res, fmax(dfs(coins, memo, m, n, i - 1, j, k - 1),
                             dfs(coins, memo, m, n, i, j - 1, k - 1)));
    }

    memo[i][j][k] = res;
    return res;
}

int maximumAmount(int** coins, int coinsSize, int* coinsColSize) {
    int m = coinsSize, n = coinsColSize[0];

    int*** memo = (int***)malloc(m * sizeof(int**));
    for (int i = 0; i < m; i++) {
        memo[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            memo[i][j] = (int*)malloc(3 * sizeof(int));
            for (int k = 0; k < 3; k++) {
                memo[i][j][k] = INT_MIN;
            }
        }
    }

    int res = dfs(coins, memo, m, n, m - 1, n - 1, 2);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(memo[i][j]);
        }
        free(memo[i]);
    }
    free(memo);

    return res;
}