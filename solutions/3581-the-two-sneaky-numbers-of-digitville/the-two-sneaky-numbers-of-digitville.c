int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(2 * sizeof(int));
    int* count = (int*)calloc(101, sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        count[x]++;
        if (count[x] == 2) {
            res[(*returnSize)++] = x;
        }
    }
    free(count);
    return res;
}