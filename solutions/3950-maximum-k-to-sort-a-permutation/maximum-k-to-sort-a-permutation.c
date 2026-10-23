int sortPermutation(int* nums, int numsSize) {
    int res = INT_MAX;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == i) {
            continue;
        }
        res &= nums[i];
    }
    return res == INT_MAX ? 0 : res;
}