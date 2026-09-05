int firstStableIndex(int* nums, int numsSize, int k) {
    int n = numsSize;
    int* minValue = (int*)malloc(n * sizeof(int));
    minValue[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        minValue[i] = fmin(minValue[i + 1], nums[i]);
    }

    int maxValue = 0;
    int result = -1;
    for (int i = 0; i < n; i++) {
        maxValue = fmax(nums[i], maxValue);
        if (maxValue - minValue[i] <= k) {
            result = i;
            break;
        }
    }

    free(minValue);
    return result;
}