class Solution {
    public int zigZagArrays(int n, int l, int r) {
        final int MOD = 1_000_000_007;
        int K = r - l + 1;

        if (n == 1) {
            return K;
        }

        long[][] prev_dp = new long[K][2];

        for (int j = 0; j < K; j++) {
            prev_dp[j][0] = j;
            prev_dp[j][1] = K - 1 - j;
        }

        for (int i = 3; i <= n; i++) {
            long[][] current_dp = new long[K][2];
            long[] P0 = new long[K];
            long[] P1 = new long[K];

            P0[0] = prev_dp[0][0];
            P1[0] = prev_dp[0][1];
            for (int p = 1; p < K; p++) {
                P0[p] = (P0[p - 1] + prev_dp[p][0]) % MOD;
                P1[p] = (P1[p - 1] + prev_dp[p][1]) % MOD;
            }
            
            long total_P0 = P0[K - 1];

            for (int j = 0; j < K; j++) {
                if (j > 0) {
                    current_dp[j][0] = P1[j - 1];
                } else {
                    current_dp[j][0] = 0;
                }

                current_dp[j][1] = (total_P0 - P0[j] + MOD) % MOD;
            }

            prev_dp = current_dp;
        }

        long totalCount = 0;
        for (int j = 0; j < K; j++) {
            totalCount = (totalCount + prev_dp[j][0] + prev_dp[j][1]) % MOD;
        }

        return (int) totalCount;
    }
}