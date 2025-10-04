class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        long[] dp = new long[k];
        long sum = 0;
        for(int i = 0; i < k; i++) sum += nums[i];
        long ans = sum;
        dp[k - 1] = sum;
        for(int i = k; i < nums.length; i++) {
            sum += nums[i] - nums[i - k];
            dp[i % k] = Math.max(sum, sum + dp[i % k]); // (i - k) % k = (i % k)
            ans = Math.max(ans, dp[i % k]);
        }
        return ans;
    }
}