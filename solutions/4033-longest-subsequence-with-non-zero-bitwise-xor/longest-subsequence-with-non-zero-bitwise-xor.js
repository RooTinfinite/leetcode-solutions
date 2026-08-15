var longestSubsequence = function (nums) {
    const n = nums.length;
    let totalXor = 0;
    let allZero = true;

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
};