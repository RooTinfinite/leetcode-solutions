int minOperations(int* nums, int numsSize, int k) {
    int operation = 0;
        for (int i = 0 ; i<numsSize;i++) {
            if (nums[i] < k) {
                operation++;
            }
        }
        return operation;
}