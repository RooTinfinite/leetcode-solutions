class Solution {
    public int minXor(int[] nums, int k) {
        int n = nums.length;

        // Step 1: Prefix XOR array
        int[] pfix = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            pfix[i] = pfix[i - 1] ^ nums[i - 1];
        }

        // Step 2: DP table
        int[][] dp = new int[n + 1][k + 1];
        for (int[] row : dp)
            Arrays.fill(row, Integer.MAX_VALUE);

        for (int i = 0; i <= n; i++) {
            dp[i][1] = pfix[i];  // Base case: 1 partition
        }

        // Step 3: Fill DP for partitions 2 to k
        for (int parts = 2; parts <= k; parts++) {
            for (int end = parts; end <= n; end++) {
                for (int split = parts - 1; split < end; split++) {
                    int segmentXOR = pfix[end] ^ pfix[split];
                    int maxXOR = Math.max(dp[split][parts - 1], segmentXOR);
                    dp[end][parts] = Math.min(dp[end][parts], maxXOR);
                }
            }
        }

        return dp[n][k];
    }
}