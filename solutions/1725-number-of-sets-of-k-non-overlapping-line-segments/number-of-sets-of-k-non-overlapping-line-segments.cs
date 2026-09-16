public class Solution {
    public int NumberOfSets(int n, int k) {
        const int MOD = 1000000007;
        int[] dp = new int[n];
        int[] prefixSums = new int[n + 1];
        for (int j = 0; j < n; j++) {
            dp[j] = 1;
            prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
        }
        for (int i = 1; i <= k; i++) {
            dp[0] = 0;
            for (int j = 1; j < n; j++)
                dp[j] = (dp[j - 1] + prefixSums[j]) % MOD;
            for (int j = 0; j < n; j++)
                prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
        }
        return dp[n - 1];
    }
}