int countPartitions(int* nums, int numsSize) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; ++i) {
        totalSum += nums[i];
    }
    return totalSum % 2 == 0 ? numsSize - 1 : 0;
}