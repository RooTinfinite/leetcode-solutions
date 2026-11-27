long long countConsistent(int* nums, int numsSize) {
    long long cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        int add = nums[i];
        int minVal = nums[i];
        for (int j = i; j < numsSize; j++) {
            add &= nums[j];
            if (nums[j] < minVal) {
                minVal = nums[j];
            }
            if (add == minVal) {
                cnt++;
            }
        }
    }
    return cnt;
}