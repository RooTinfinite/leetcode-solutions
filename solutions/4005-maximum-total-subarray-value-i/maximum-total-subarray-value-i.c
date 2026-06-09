long long maxTotalValue(int* nums, int numsSize, int k) {
    int m1 = INT_MAX, m2 = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        m1 = fmin(m1, nums[i]);
        m2 = fmax(m2, nums[i]);
    }
    return (long long)(m2 - m1) * k;
}