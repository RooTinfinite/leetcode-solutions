typedef struct {
    int key;
    UT_hash_handle hh;
} HashSetItem;

HashSetItem* hashSetFind(HashSetItem** set, int key) {
    HashSetItem* entry = NULL;
    HASH_FIND_INT(*set, &key, entry);
    return entry;
}

bool hashSetAdd(HashSetItem** set, int key) {
    if (hashSetFind(set, key)) {
        return false;
    }
    HashSetItem* entry = (HashSetItem*)malloc(sizeof(HashSetItem));
    entry->key = key;
    HASH_ADD_INT(*set, key, entry);
    return true;
}

bool hashSetContains(HashSetItem** set, int key) {
    return hashSetFind(set, key) != NULL;
}

void hashSetFree(HashSetItem** set) {
    HashSetItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *set, curr, tmp) {
        HASH_DEL(*set, curr);
        free(curr);
    }
}

int missingMultiple(int* nums, int numsSize, int k) {
    HashSetItem* seen = NULL;
    for (int i = 0; i < numsSize; i++) {
        hashSetAdd(&seen, nums[i]);
    }
    int ans = k;
    while (hashSetContains(&seen, ans)) {
        ans += k;
    }

    hashSetFree(&seen);
    return ans;
}