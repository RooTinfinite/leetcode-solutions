function longestSubsequence(nums: number[]): number {
    const n: number = nums.length;
    let totalXor: number = 0;
    let allZero: boolean = true;

    for (const x of nums) {
        totalXor ^= x;
        if (x > 0) {
            allZero = false;
        }
    }

    if (totalXor > 0) {
        return n;
    }

    return allZero ? 0 : n - 1;
}