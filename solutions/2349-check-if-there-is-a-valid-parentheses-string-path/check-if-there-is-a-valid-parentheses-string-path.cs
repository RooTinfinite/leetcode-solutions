public class Solution {
    public bool HasValidPath(char[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        int pathLen = n + m - 1;

        if (pathLen % 2 == 1) {
            return false;
        }
        if (grid[0][0] != '(' || grid[n - 1][m - 1] != ')') {
            return false;
        }

        BigInteger[][] dp = new BigInteger[n][];

        for (int i = 0; i < n; ++i) {
            dp[i] = new BigInteger[m];
        }

        dp[0][0] = BigInteger.One << 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int change = grid[i][j] == '(' ? 1 : -1;

                if (i > 0) {
                    if (change == 1) {
                        dp[i][j] |= dp[i - 1][j] << 1;
                    } else {
                        dp[i][j] |= dp[i - 1][j] >> 1;
                    }
                }

                if (j > 0) {
                    if (change == 1) {
                        dp[i][j] |= dp[i][j - 1] << 1;
                    } else {
                        dp[i][j] |= dp[i][j - 1] >> 1;
                    }
                }
            }
        }

        return (dp[n - 1][m - 1] & 1) == 1;
    }
}