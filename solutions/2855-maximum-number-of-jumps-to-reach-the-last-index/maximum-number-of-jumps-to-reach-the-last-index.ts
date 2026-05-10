function maximumJumps(nums: number[], target: number): number {
    const n: number = nums.length;
    const dp: number[] = new Array(n).fill(Number.MIN_SAFE_INTEGER);
    dp[0] = 0;

    for (let i: number = 1; i < n; i++) {
        for (let j: number = 0; j < i; j++) {
            if (Math.abs(nums[j] - nums[i]) <= target) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1] < 0 ? -1 : dp[n - 1];
}