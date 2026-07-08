class Solution {

    public long eval(int[] nums, int start, int end, int k, int[] cost) {
        int n = nums.length;
        long INF = (long)1e18;

        long[][] dp = new long[n + 2][k + 1];
        for (int i = 0; i < n + 2; i++) {
            Arrays.fill(dp[i], INF);
        }

        dp[start][0] = 0;

        for (int i = start; i <= end; i++) {
            for (int j = 0; j <= k; j++) {
                if (dp[i][j] == INF) continue;

                // Skip current
                dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j]);

                // Take current
                if (j + 1 <= k) {
                    dp[i + 2][j + 1] = Math.min(dp[i + 2][j + 1], dp[i][j] + cost[i]);
                }
            }
        }

        return Math.min(dp[end + 1][k], dp[end + 2][k]);
    }

    public int minOperations(int[] nums, int k) {
        int n = nums.length;

        if (k > n / 2) return -1;
        if (k == 0) return 0;
        if (n == 2) return nums[0] == nums[1] ? 1 : 0;

        int[] cost = new int[n];
        for (int i = 0; i < n; i++) {
            int left = nums[(i - 1 + n) % n];
            int right = nums[(i + 1) % n];
            cost[i] = Math.max(0, Math.max(left, right) + 1 - nums[i]);
        }

        long ans = Long.MAX_VALUE;

        // Case 1: skip index 0
        ans = Math.min(ans, eval(nums, 1, n - 1, k, cost));

        // Case 2: take index 0
        if (k >= 1) {
            long val = cost[0] + eval(nums, 2, n - 2, k - 1, cost);
            ans = Math.min(ans, val);
        }

        return ans == Long.MAX_VALUE ? -1 : (int) ans;
    }
}