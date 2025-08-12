public class Solution {
    public int NumberOfWays(int n, int x) {
        const int MOD = 1_000_000_007;
        long[] dp = new long[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int val = (int)Math.Pow(i, x);
            if (val > n) {
                break;
            }
            for (int j = n; j >= val; j--) {
                dp[j] = (dp[j] + dp[j - val]) % MOD;
            }
        }
        return (int)dp[n];
    }
}