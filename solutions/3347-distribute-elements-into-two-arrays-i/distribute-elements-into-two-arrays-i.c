void reverse(int* arr, int left, int right) {
    while (left < right) {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
}

int* resultArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* arr = (int*)malloc(sizeof(int) * numsSize);
    arr[0] = nums[0];
    arr[numsSize - 1] = nums[1];
    int idx = 0, revIdx = numsSize - 1;
    for (int i = 2; i < numsSize; i++) {
        if (arr[idx] > arr[revIdx]) {
            arr[++idx] = nums[i];
        } else {
            arr[--revIdx] = nums[i];
        }
    }
    reverse(arr, revIdx, numsSize - 1);
    return arr;
}