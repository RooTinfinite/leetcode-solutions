#define MOD 1000000007

int* pathsWithMaxScore(char** board, int boardSize, int* returnSize) {
    int n = boardSize;
    int*** dp = (int***)malloc(n * sizeof(int**));
    for (int i = 0; i < n; i++) {
        dp[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            dp[i][j] = (int*)malloc(2 * sizeof(int));
            dp[i][j][0] = -1;
            dp[i][j][1] = 0;
        }
    }
    dp[n - 1][n - 1][0] = 0;
    dp[n - 1][n - 1][1] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (!(i == n - 1 && j == n - 1) && board[i][j] != 'X') {
                if (i + 1 < n && dp[i + 1][j][0] != -1) {
                    if (dp[i + 1][j][0] > dp[i][j][0]) {
                        dp[i][j][0] = dp[i + 1][j][0];
                        dp[i][j][1] = dp[i + 1][j][1];
                    } else if (dp[i + 1][j][0] == dp[i][j][0]) {
                        dp[i][j][1] = (dp[i][j][1] + dp[i + 1][j][1]) % MOD;
                    }
                }
                if (j + 1 < n && dp[i][j + 1][0] != -1) {
                    if (dp[i][j + 1][0] > dp[i][j][0]) {
                        dp[i][j][0] = dp[i][j + 1][0];
                        dp[i][j][1] = dp[i][j + 1][1];
                    } else if (dp[i][j + 1][0] == dp[i][j][0]) {
                        dp[i][j][1] = (dp[i][j][1] + dp[i][j + 1][1]) % MOD;
                    }
                }
                if (i + 1 < n && j + 1 < n && dp[i + 1][j + 1][0] != -1) {
                    if (dp[i + 1][j + 1][0] > dp[i][j][0]) {
                        dp[i][j][0] = dp[i + 1][j + 1][0];
                        dp[i][j][1] = dp[i + 1][j + 1][1];
                    } else if (dp[i + 1][j + 1][0] == dp[i][j][0]) {
                        dp[i][j][1] = (dp[i][j][1] + dp[i + 1][j + 1][1]) % MOD;
                    }
                }
                if (dp[i][j][0] != -1 && board[i][j] != 'E') {
                    dp[i][j][0] += board[i][j] - '0';
                }
            }
        }
    }
    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    if (dp[0][0][0] != -1) {
        res[0] = dp[0][0][0];
        res[1] = dp[0][0][1] % MOD;
    } else {
        res[0] = 0;
        res[1] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);
    return res;
}