int smallestIndex(const int* nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        int num = nums[i];
        int digitSum = 0;

        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }

        if (digitSum == i) {
            return i;
        }
    }

    return -1;
}