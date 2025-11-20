bool isScramble(char* s1, char* s2) {
    int n = strlen(s1);
    bool dp[n + 1][n][n];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[1][i][j] = s1[i] == s2[j];
        }
    }
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n + 1 - length; i++) {
            for (int j = 0; j < n + 1 - length; j++) {
                for (int newLength = 1; newLength < length; newLength++) {
                    bool* dp1 = dp[newLength][i];
                    bool* dp2 = dp[length - newLength][i + newLength];
                    dp[length][i][j] =
                        dp[length][i][j] || (dp1[j] && dp2[j + newLength]);
                    dp[length][i][j] = dp[length][i][j] ||
                                       (dp1[j + length - newLength] && dp2[j]);
                }
            }
        }
    }
    return dp[n][0][0];
}