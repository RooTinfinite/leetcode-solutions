struct ht_item {
    int key;
    int count;
    UT_hash_handle hh;
};
void backtrack(int* nums, int numsSize, int* comb, int combSize, int** res,
               int* returnSize, int** returnColumnSizes,
               struct ht_item* counter) {
    if (combSize == numsSize) {
        res[*returnSize] = malloc(numsSize * sizeof(int));
        memcpy(res[*returnSize], comb, numsSize * sizeof(int));
        returnColumnSizes[0][*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    struct ht_item *item, *tmp;
    HASH_ITER(hh, counter, item, tmp) {
        if (item->count > 0) {
            comb[combSize] = item->key;
            item->count--;
            backtrack(nums, numsSize, comb, combSize + 1, res, returnSize,
                      returnColumnSizes, counter);
            item->count++;
        }
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize,
                    int** returnColumnSizes) {
    struct ht_item *counter = NULL, *item;
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(counter, &nums[i], item);
        if (item == NULL) {
            item = malloc(sizeof(struct ht_item));
            item->key = nums[i];
            item->count = 1;
            HASH_ADD_INT(counter, key, item);
        } else {
            item->count++;
        }
    }
    int** res = malloc(10000 * sizeof(int*));
    *returnColumnSizes = malloc(10000 * sizeof(int));
    *returnSize = 0;
    int* comb = malloc(numsSize * sizeof(int));
    backtrack(nums, numsSize, comb, 0, res, returnSize, returnColumnSizes,
              counter);
    return res;
}