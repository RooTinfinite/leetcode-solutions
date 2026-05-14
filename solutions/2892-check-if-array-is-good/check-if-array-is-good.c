bool isGood(int* nums, int numsSize) {
    int n = numsSize;
    int* count = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        int a = nums[i];
        if (a < 1 || a >= n) {
            free(count);
            return false;
        }
        if (a < n - 1 && count[a] > 0) {
            free(count);
            return false;
        }
        if (a == n - 1 && count[a] > 1) {
            free(count);
            return false;
        }
        count[a]++;
    }
    free(count);
    return true;
}