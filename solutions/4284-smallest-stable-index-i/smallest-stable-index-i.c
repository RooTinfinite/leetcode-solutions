int firstStableIndex(int* nums, int numsSize, int k) {
    int n = numsSize;
    for (int i = 0; i < n; i++) {
        int maxValue = nums[i];
        int minValue = nums[i];
        for (int j = 0; j < i; j++) {
            maxValue = fmax(maxValue, nums[j]);
        }
        for (int j = i + 1; j < n; j++) {
            minValue = fmin(minValue, nums[j]);
        }
        if (maxValue - minValue <= k) {
            return i;
        }
    }
    return -1;
}