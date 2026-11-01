int minMoves(int* nums, int numsSize) {
    int sum = 0, min = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        min = fmin(min, nums[i]);
    }
    return sum - numsSize * min;
}