double knightProbability(int n, int k, int row, int column) {
    double dp[n][n];
    memset(dp, 0, sizeof(dp));
    dp[row][column] = 1;

    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    for (int move = 1; move <= k; move++) {
        double newDp[n][n];
        memset(newDp, 0, sizeof(newDp));
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                for (int i = 0; i < 8; i++) {
                    int newR = r + moves[i][0];
                    int newC = c + moves[i][1];
                    if (newR >= 0 && newR < n && newC >= 0 && newC < n) {
                        newDp[r][c] += dp[newR][newC] / 8.0;
                    }
                }
            }
        }
        memcpy(dp, newDp, sizeof(dp));
    }

    double probability = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            probability += dp[r][c];
        }
    }

    return probability;
}