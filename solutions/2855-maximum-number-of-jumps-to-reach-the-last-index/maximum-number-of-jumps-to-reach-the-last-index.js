var maximumJumps = function (nums, target) {
    const n = nums.length;
    const dp = new Array(n).fill(Number.MIN_SAFE_INTEGER);
    dp[0] = 0;

    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (Math.abs(nums[j] - nums[i]) <= target) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1] < 0 ? -1 : dp[n - 1];
};