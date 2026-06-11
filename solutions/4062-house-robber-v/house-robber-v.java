class Solution {
    public long rob(int[] nums, int[] colors) {
        int n = nums.length;
        long[] dp = new long[n + 1];

        Arrays.fill(dp, -1);

        dp[0] = 0;
        dp[1] = nums[0];

        long ans = nums[0];

        for (int i = 1; i < n; i++) {
            dp[i + 1] = nums[i];

            if (colors[i - 1] != colors[i]) {
                dp[i + 1] = Math.max(dp[i + 1], dp[i] + nums[i]);
            }

            if (i - 1 >= 0) {
                dp[i + 1] = Math.max(dp[i + 1], dp[i - 1] + nums[i]);
            }

            if (i - 2 >= 0) {
                dp[i + 1] = Math.max(dp[i + 1], dp[i - 2] + nums[i]);
            }

            ans = Math.max(ans, dp[i + 1]);
        }

        return ans;
    }
}