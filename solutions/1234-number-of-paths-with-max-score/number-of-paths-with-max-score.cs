public class Solution {
    private const int MOD = 1000000007;

    public int[] PathsWithMaxScore(IList<string> board) {
        int n = board.Count;
        int[][][] dp = new int [n][][];
        for (int i = 0; i < n; i++) {
            dp[i] = new int [n][];
            for (int j = 0; j < n; j++) {
                dp[i][j] = new int[] { -1, 0 };
            }
        }
        dp[n - 1][n - 1][0] = 0;
        dp[n - 1][n - 1][1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (!(i == n - 1 && j == n - 1) && board[i][j] != 'X') {
                    Update(dp, i, j, i + 1, j, n);
                    Update(dp, i, j, i, j + 1, n);
                    Update(dp, i, j, i + 1, j + 1, n);
                    if (dp[i][j][0] != -1) {
                        dp[i][j][0] +=
                            (board[i][j] == 'E' ? 0 : board[i][j] - '0');
                    }
                }
            }
        }
        if (dp[0][0][0] != -1) {
            return new int[] { dp[0][0][0], dp[0][0][1] % MOD };
        }
        return new int[] { 0, 0 };
    }

    private void Update(int[][][] dp, int x, int y, int u, int v, int n) {
        if (u >= n || v >= n || dp[u][v][0] == -1) {
            return;
        }
        if (dp[u][v][0] > dp[x][y][0]) {
            dp[x][y][0] = dp[u][v][0];
            dp[x][y][1] = dp[u][v][1];
        } else if (dp[u][v][0] == dp[x][y][0]) {
            dp[x][y][1] = (dp[x][y][1] + dp[u][v][1]) % MOD;
        }
    }
}