int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    int cnt1 = 0;  // Number of elements less than target
    int cnt2 = 0;  // Number of elements equal to target

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < target) {
            cnt1++;
        } else if (nums[i] == target) {
            cnt2++;
        }
    }

    int* res = (int*)malloc(cnt2 * sizeof(int));
    for (int i = 0; i < cnt2; i++) {
        res[i] = cnt1 + i;
    }

    *returnSize = cnt2;
    return res;
}