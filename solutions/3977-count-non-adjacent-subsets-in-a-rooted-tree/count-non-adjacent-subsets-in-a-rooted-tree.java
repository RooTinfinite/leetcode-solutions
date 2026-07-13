class Solution {

    static final int MOD = 1000000007;

    public int countValidSubsets(int[] parent, int[] nums, int k) {
        int n = parent.length;

        int[] h = new int[n];
        int[] to = new int[n - 1];
        int[] nx = new int[n - 1];

        for (int i = 0; i < n; i++)
            h[i] = -1;

        int idx = 0;

        for (int i = 1; i < n; i++) {
            to[idx] = i;
            nx[idx] = h[parent[i]];
            h[parent[i]] = idx++;
        }

        long[][][] dp0 = new long[n][2][k];
        dfs(0, h, to, nx, nums, k, dp0);
        long res = dp0[0][0][0];
        res = (res + dp0[0][1][0]) % MOD;
        res = (res - 1 + MOD) % MOD;
        return (int) res;
    }

    private void dfs(int u, int[] h, int[] to, int[] nx, int[] nums, int k, long[][][] dp) {
        dp[u][0][0] = 1;
        dp[u][1][nums[u] % k] = 1;

        for (int e = h[u]; e != -1; e = nx[e]) {
            int v = to[e];
            dfs(v, h, to, nx, nums, k, dp);

            long[] nd0 = new long[k];
            long[] nd1 = new long[k];

            for (int a = 0; a < k; a++) {
                if (dp[u][0][a] != 0) {
                    for (int b = 0; b < k; b++) {
                        long ways = (dp[v][0][b] + dp[v][1][b]) % MOD;
                        if (ways == 0)
                            continue;
                        int nm = (a + b) % k;
                        nd0[nm] = (nd0[nm] + dp[u][0][a] * ways) % MOD;
                    }
                }

                if (dp[u][1][a] != 0) {
                    for (int b = 0; b < k; b++) {
                        long ways = dp[v][0][b];
                        if (ways == 0)
                            continue;
                        int nm = (a + b) % k;
                        nd1[nm] = (nd1[nm] + dp[u][1][a] * ways) % MOD;
                    }
                }
            }

            for (int i = 0; i < k; i++) {
                dp[u][0][i] = nd0[i];
                dp[u][1][i] = nd1[i];
            }
        }
    }
}