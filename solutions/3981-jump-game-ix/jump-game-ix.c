typedef struct {
    int value;
    int left;
    int right;
} Item;

int* maxValue(const int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    memset(ans, 0, numsSize * sizeof(int));

    Item* stack = (Item*)malloc(numsSize * sizeof(Item));
    int stackSize = 0;
    for (int i = 0; i < numsSize; i++) {
        Item curr = {nums[i], i, i};
        while (stackSize > 0 && stack[stackSize - 1].value > nums[i]) {
            Item top = stack[stackSize - 1];
            stackSize--;
            curr.value = (top.value > curr.value) ? top.value : curr.value;
            curr.left = top.left;
        }

        stack[stackSize++] = curr;
    }

    for (int i = 0; i < stackSize; i++) {
        for (int j = stack[i].left; j <= stack[i].right; j++) {
            ans[j] = stack[i].value;
        }
    }

    free(stack);
    *returnSize = numsSize;
    return ans;
}