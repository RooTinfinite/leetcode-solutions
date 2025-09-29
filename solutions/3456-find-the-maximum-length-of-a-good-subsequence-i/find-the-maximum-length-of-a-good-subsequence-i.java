class Solution {
    public int maximumLength(int[] nums, int k) {
        Integer dp[][][] = new Integer[nums.length + 1][nums.length + 1][k + 1];
        return solve(nums, 0, k, -1, dp);
    }

    private int solve(int[] nums, int idx, int k, int lastIdx, Integer[][][] dp) {
        if (idx >= nums.length || k < 0) {
            return 0;
        }

        if(dp[idx][lastIdx+1][k]!=null)
            return dp[idx][lastIdx+1][k];

        int maximum = Integer.MIN_VALUE;
        if (lastIdx == -1 || nums[idx] == nums[lastIdx]) {
            maximum = Math.max(maximum, 1 + solve(nums, idx + 1, k, idx, dp));
        }

        if (lastIdx != -1 && nums[idx] != nums[lastIdx] && k > 0) {
            maximum = Math.max(maximum, 1 + solve(nums, idx + 1, k - 1, idx, dp));
        }

        maximum = Math.max(maximum, solve(nums, idx + 1, k, lastIdx, dp));

        return dp[idx][lastIdx+1][k] = maximum;
    }
}