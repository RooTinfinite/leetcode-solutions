function minimumOperations(nums: number[]): number {
    return nums.reduce((pre, v) => (pre += Math.min(3 - (v % 3), v % 3)), 0);
}