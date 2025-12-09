#define MOD 1000000007

typedef struct {
    int key;
    int* indices;
    int size;
    int capacity;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int index) {
    HashItem* pEntry = hashFindItem(obj, key);
    if (pEntry) {
        if (pEntry->size >= pEntry->capacity) {
            pEntry->capacity *= 2;
            pEntry->indices =
                realloc(pEntry->indices, pEntry->capacity * sizeof(int));
        }
        pEntry->indices[pEntry->size++] = index;
    } else {
        pEntry = (HashItem*)malloc(sizeof(HashItem));
        pEntry->key = key;
        pEntry->capacity = 32;
        pEntry->size = 1;
        pEntry->indices = malloc(pEntry->capacity * sizeof(int));
        pEntry->indices[0] = index;
        HASH_ADD_INT(*obj, key, pEntry);
    }

    return true;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr->indices);
        free(curr);
    }
}

int upperBound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int specialTriplets(int* nums, int numsSize) {
    HashItem* pos = NULL;
    for (int i = 0; i < numsSize; i++) {
        hashAddItem(&pos, nums[i], i);
    }

    int ans = 0;
    for (int i = 1; i < numsSize - 1; i++) {
        int target = nums[i] * 2;
        HashItem* pEntry = hashFindItem(&pos, target);
        if (pEntry == NULL || pEntry->size <= 1) {
            continue;
        }

        int* targetPos = pEntry->indices;
        int arrSize = pEntry->size;
        if (targetPos[0] >= i) {
            continue;
        }

        int split = upperBound(targetPos, arrSize, i);
        int l = split;
        int r = arrSize - split;
        if (nums[i] == 0) {
            l--;
        }
        if (l > 0 && r > 0) {
            ans = (int)((ans + (long long)l * r) % MOD);
        }
    }

    hashFree(&pos);
    return ans;
}