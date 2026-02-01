int minimumCost(int* nums, int numsSize) {
    int min = nums[0], min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min1)
            min1 = nums[i];
    }
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == min1) {
            nums[i] = INT_MIN;
            break;
        }
    }
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min2 && nums[i] != INT_MIN)
            min2 = nums[i];
    }
    return min + min1 + min2;
}