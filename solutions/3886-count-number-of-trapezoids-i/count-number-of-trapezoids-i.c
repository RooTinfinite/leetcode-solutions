typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int countTrapezoids(int** points, int pointsSize, int* pointsColSize) {
    HashItem* pointNum = NULL;
    const int mod = 1e9 + 7;
    long long ans = 0, sum = 0;
    for (int i = 0; i < pointsSize; i++) {
        hashSetItem(&pointNum, points[i][1],
                    hashGetItem(&pointNum, points[i][1], 0) + 1);
    }
    for (HashItem* pEntry = pointNum; pEntry; pEntry = pEntry->hh.next) {
        int pNum = pEntry->val;
        long long edge = (long long)pNum * (pNum - 1) / 2;
        ans += edge * sum;
        sum += edge;
    }
    hashFree(&pointNum);
    return ans % mod;
}