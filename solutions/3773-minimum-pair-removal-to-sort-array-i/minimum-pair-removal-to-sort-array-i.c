int minimumPairRemoval(int* nums, int numsSize) {
    int count = 0;
    int size = numsSize;

    while (size > 1) {
        int isAscending = 1;
        int minSum = INT_MAX;
        int targetIndex = -1;
        for (int i = 0; i < size - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (nums[i] > nums[i + 1]) {
                isAscending = 0;
            }
            if (sum < minSum) {
                minSum = sum;
                targetIndex = i;
            }
        }

        if (isAscending) {
            break;
        }
        count++;
        nums[targetIndex] = minSum;
        for (int i = targetIndex + 1; i < size - 1; i++) {
            nums[i] = nums[i + 1];
        }
        size--;
    }

    return count;
}