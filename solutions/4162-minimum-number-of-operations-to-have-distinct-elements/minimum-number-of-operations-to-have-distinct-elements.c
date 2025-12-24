int minOperations(int* nums, int numsSize) {
    int* hash = (int*)malloc(100001 * sizeof(int));
    int i = 0;
    for(i = numsSize - 1; i >= 0; i--) {
        if(hash[nums[i]] == 1) break;
        hash[nums[i]] = 1;
    }
    free(hash);
    return (i + 3) / 3;
}