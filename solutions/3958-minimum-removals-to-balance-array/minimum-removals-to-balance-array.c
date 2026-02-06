int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int minRemoval(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    int ans = numsSize;
    int right = 0;

    for (int left = 0; left < numsSize; left++) {
        while (right < numsSize &&
               (long long)nums[right] <= (long long)nums[left] * k) {
            right++;
        }
        int current = numsSize - (right - left);
        if (current < ans) {
            ans = current;
        }
    }

    return ans;
}