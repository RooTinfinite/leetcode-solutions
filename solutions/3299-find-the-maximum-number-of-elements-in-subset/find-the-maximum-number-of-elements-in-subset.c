typedef struct {
    long long key;
    int cnt;
    UT_hash_handle hh;
} HashNode;

static HashNode* find(HashNode* map, long long key) {
    HashNode* p;
    HASH_FIND(hh, map, &key, sizeof(key), p);
    return p;
}

int maximumLength(int* nums, int numsSize) {
    HashNode* map = NULL;

    for (int i = 0; i < numsSize; i++) {
        long long key = nums[i];
        HashNode* p = find(map, key);

        if (p == NULL) {
            p = malloc(sizeof(HashNode));
            p->key = key;
            p->cnt = 1;
            HASH_ADD(hh, map, key, sizeof(key), p);
        } else {
            p->cnt++;
        }
    }

    HashNode* p = find(map, 1);
    // ans is at least the number of occurrences of 1, rounded down to an odd
    // number
    int oneCnt = p ? p->cnt : 0;
    int ans = (oneCnt & 1) ? oneCnt : oneCnt - 1;

    if (p) {
        HASH_DEL(map, p);
        free(p);
    }

    HashNode *cur, *tmp;
    HASH_ITER(hh, map, cur, tmp) {
        int res = 0;
        long long x = cur->key;

        while ((p = find(map, x)) && p->cnt > 1) {
            res += 2;
            x *= x;
        }

        int cand = res + (find(map, x) ? 1 : -1);
        if (cand > ans) {
            ans = cand;
        }
    }

    HASH_ITER(hh, map, cur, tmp) {
        HASH_DEL(map, cur);
        free(cur);
    }

    return ans;
}