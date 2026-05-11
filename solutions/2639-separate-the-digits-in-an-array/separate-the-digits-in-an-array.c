int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int totalDigits = 0;
    for (int i = numsSize - 1; i >= 0; i--) {
        int x = nums[i];
        while (x > 0) {
            totalDigits++;
            x /= 10;
        }
    }

    int* temp = (int*)malloc(totalDigits * sizeof(int));
    int index = 0;
    for (int i = numsSize - 1; i >= 0; i--) {
        int x = nums[i];
        while (x > 0) {
            temp[index++] = x % 10;
            x /= 10;
        }
    }

    int* res = (int*)malloc(totalDigits * sizeof(int));
    for (int i = 0; i < totalDigits; i++) {
        res[i] = temp[totalDigits - 1 - i];
    }

    free(temp);
    *returnSize = totalDigits;
    return res;
}