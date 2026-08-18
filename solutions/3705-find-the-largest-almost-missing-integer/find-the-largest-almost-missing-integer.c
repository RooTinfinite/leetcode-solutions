int largestInteger(int* nums, int numsSize, int k) {
    int n = numsSize;
    if (n == k) {
        int res = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > res) {
                res = nums[i];
            }
        }
        return res;
    }
    int count[51] = {0};
    for (int i = 0; i < n; ++i) {
        count[nums[i]]++;
    }
    if (k == 1) {
        for (int i = 50; i >= 0; --i) {
            if (count[i] == 1) {
                return i;
            }
        }
        return -1;
    }
    int res = -1;
    if (count[nums[0]] == 1) {
        res = fmax(res, nums[0]);
    }
    if (count[nums[n - 1]] == 1) {
        res = MAX(res, nums[n - 1]);
    }
    return res;
}