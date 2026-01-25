#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmp(const void* pa, const void* pb) { return *(int*)pa - *(int*)pb; }

int minimumDifference(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = INT_MAX;
    for (int i = 0; i + k - 1 < numsSize; ++i) {
        ans = MIN(ans, nums[i + k - 1] - nums[i]);
    }
    return ans;
}