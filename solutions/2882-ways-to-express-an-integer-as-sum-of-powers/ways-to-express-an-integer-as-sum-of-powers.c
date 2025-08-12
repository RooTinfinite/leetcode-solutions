int numberOfWays(int n, int x) {
    const int mod = 1000000007;
    int* dp = calloc(n + 1, sizeof(int));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int val = (int)pow(i, x);
        if (val > n) {
            break;
        }
        for (int j = n; j >= val; j--) {
            dp[j] = (dp[j] + dp[j - val]) % mod;
        }
    }
    int result = dp[n];
    free(dp);

    return result;
}