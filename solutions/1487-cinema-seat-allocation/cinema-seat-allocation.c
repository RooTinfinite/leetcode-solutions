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

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize,
                        int* reservedSeatsColSize) {
    int left = 0b11110000;
    int middle = 0b11000011;
    int right = 0b00001111;
    HashItem* occupied = NULL;

    for (int i = 0; i < reservedSeatsSize; i++) {
        int seatCol = reservedSeats[i][1];
        if (seatCol >= 2 && seatCol <= 9) {
            int row = reservedSeats[i][0];
            int currentVal = hashGetItem(&occupied, row, 0);
            int newVal = currentVal | (1 << (seatCol - 2));
            hashSetItem(&occupied, row, newVal);
        }
    }

    int occupiedCount = HASH_COUNT(occupied);
    int ans = (n - occupiedCount) * 2;

    HashItem *curr, *tmp;
    HASH_ITER(hh, occupied, curr, tmp) {
        int bitmask = curr->val;
        if ((bitmask | left) == left || (bitmask | middle) == middle ||
            (bitmask | right) == right) {
            ans++;
        }
    }

    hashFree(&occupied);
    return ans;
}