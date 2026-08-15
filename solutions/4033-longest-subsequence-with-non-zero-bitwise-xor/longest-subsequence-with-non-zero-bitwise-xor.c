int longestSubsequence(int* nums, int numsSize) {
    int totalXor = 0;
    int allZero = 1;

    for (int i = 0; i < numsSize; i++) {
        totalXor ^= nums[i];
        if (nums[i] > 0) {
            allZero = 0;
        }
    }
    if (totalXor > 0) {
        return numsSize;
    }

    return allZero ? 0 : numsSize - 1;
}