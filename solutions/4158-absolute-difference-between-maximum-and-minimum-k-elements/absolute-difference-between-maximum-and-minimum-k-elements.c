int compare(const void* a,const void* b) {
    return *(int*)a - *(int*)b;
}
int absDifference(int* nums, int numsSize, int k) {
    int max_sum = 0, min_sum = 0;
    qsort(nums,numsSize,sizeof(int),compare);
    for(int i = 0, j = numsSize - 1; i < k; i++, j--) {
        min_sum += nums[i];
        max_sum += nums[j];
    }
    return max_sum - min_sum;
}