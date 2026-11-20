typedef struct {
    int key;
    int length;
    UT_hash_handle hh;
} HashEntry;

int cmp(const void* a, const void* b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int maxSelectedElements(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    HashEntry *dp = NULL, *entry, *tmp;
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        // Compute the case of increasing by 1 before the case of leaving
        // unchanged.
        for (int d = 1; d >= 0; d--) {
            int key = nums[i] + d, prevKey = key - 1;
            HASH_FIND_INT(dp, &prevKey, entry);
            int length = (entry == NULL ? 0 : entry->length) + 1;

            HASH_FIND_INT(dp, &key, entry);
            if (entry == NULL) {
                entry = malloc(sizeof(HashEntry));
                entry->key = key;
                entry->length = 0;
                HASH_ADD_INT(dp, key, entry);
            }
            if (length > entry->length) {
                entry->length = length;
            }
            if (entry->length > ans) {
                ans = entry->length;
            }
        }
    }

    HASH_ITER(hh, dp, entry, tmp) {
        HASH_DEL(dp, entry);
        free(entry);
    }
    return ans;
}