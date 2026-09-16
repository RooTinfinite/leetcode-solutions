int numberOfSets(int n, int k) {
    const int MOD = 1000000007;
    int* dp = malloc(n * sizeof(int));
    int* prefixSums = calloc(n + 1, sizeof(int));
    for (int j = 0; j < n; j++) {
        dp[j] = 1;
        prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
    }
    for (int i = 1; i <= k; i++) {
        dp[0] = 0;
        for (int j = 1; j < n; j++) {
            dp[j] = (dp[j - 1] + prefixSums[j]) % MOD;
        }
        for (int j = 0; j < n; j++) {
            prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
        }
    }
    int answer = dp[n - 1];
    free(dp);
    free(prefixSums);
    return answer;
}