class Solution {
    long r(int[] nums, int pos, int skip, long[][] dp) {
        int n = nums.length;
        if (pos >= n - 1) return 0;

        if (dp[skip][pos] != -1) return dp[skip][pos];

        long cost = Math.max(0, Math.max(nums[pos - 1], nums[pos + 1]) + 1L - nums[pos]);

        if (skip == 1) {
            return dp[skip][pos] = cost + r(nums, pos + 2, skip, dp);
        }

        long takeNormal = cost + r(nums, pos + 2, 0, dp);
        long takeSkip   = cost + r(nums, pos + 3, 1, dp);

        dp[1][pos] = takeSkip;
        dp[0][pos] = takeNormal;

        return dp[skip][pos] = Math.min(takeNormal, takeSkip);
    }

    public long minIncrease(int[] nums) {
        int n = nums.length;

        // Odd length: fixed pattern
        if (n % 2 == 1) {
            long ans = 0;
            for (int i = 1; i < n - 1; i += 2) {
                ans += Math.max(0, Math.max(nums[i - 1], nums[i + 1]) + 1L - nums[i]);
            }
            return ans;
        }

        // Even length: DP
        long[][] dp = new long[2][n];
        for (long[] row : dp) Arrays.fill(row, -1);

        return Math.min(
            r(nums, 1, 0, dp),
            r(nums, 2, 1, dp)
        );
    }
}