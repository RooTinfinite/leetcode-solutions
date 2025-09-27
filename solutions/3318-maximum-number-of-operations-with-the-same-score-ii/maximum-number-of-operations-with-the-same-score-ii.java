class Solution {
    int[][] dp;

    public int maxOperations(int[] nums) {
        int n = nums.length;
        dp = new int[n][n];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        int ans = 0;

        ans = Math.max(ans, 1 + func(2, n - 1, nums, nums[0] + nums[1]));
        ans = Math.max(ans, 1 + func(0, n - 3, nums, nums[n - 1] + nums[n - 2]));
        ans = Math.max(ans, 1 + func(1, n - 2, nums, nums[0] + nums[n - 1]));

        return ans;
    }

    private int func(int l, int r, int[] nums, int num) {
        if (l >= r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;
        if (nums[l] + nums[l + 1] == num) {
            ans = Math.max(ans, 1 + func(l + 2, r, nums, num));
        }
        if (nums[r] + nums[r - 1] == num) {
            ans = Math.max(ans, 1 + func(l, r - 2, nums, num));
        }
        if (nums[l] + nums[r] == num) {
            ans = Math.max(ans, 1 + func(l + 1, r - 1, nums, num));
        }

        return dp[l][r] = ans;
    }
}