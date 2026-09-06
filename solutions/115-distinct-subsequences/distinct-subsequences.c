long long MOD = 1e9 + 7;
int numDistinct(char* s, char* t) {
    int M = strlen(s);
    int N = strlen(t);
    long long dp[M + 1][N + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= M; i++) dp[i][N] = 1;
    for (int i = M - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            dp[i][j] = dp[i + 1][j];
            if (s[i] == t[j]) {
                dp[i][j] += dp[i + 1][j + 1];
                dp[i][j] %= MOD;
            }
        }
    }
    return (int)dp[0][0];
}