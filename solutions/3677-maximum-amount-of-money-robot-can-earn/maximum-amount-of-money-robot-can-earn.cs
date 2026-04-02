public class Solution {
    public int MaximumAmount(int[][] coins) {
        int m = coins.Length, n = coins[0].Length;
        int[,,] memo = new int[m, n, 3];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    memo[i, j, k] = int.MinValue;
                }
            }
        }

        return DFS(coins, memo, 0, 0, 2);
    }

    private int DFS(int[][] coins, int[,,] memo, int i, int j, int k) {
        int m = coins.Length, n = coins[0].Length;
        if (i >= m || j >= n) {
            return int.MinValue;
        }

        int x = coins[i][j];
        // arrive at the destination
        if (i == m - 1 && j == n - 1) {
            return k > 0 ? Math.Max(0, x) : x;
        }

        if (memo[i, j, k] != int.MinValue) {
            return memo[i, j, k];
        }

        // not neutralize
        int res = Math.Max(DFS(coins, memo, i + 1, j, k),
                           DFS(coins, memo, i, j + 1, k)) +
                  x;

        if (k > 0 && x < 0) {
            // neutralize
            res = Math.Max(res, Math.Max(DFS(coins, memo, i + 1, j, k - 1),
                                         DFS(coins, memo, i, j + 1, k - 1)));
        }

        memo[i, j, k] = res;
        return res;
    }
}