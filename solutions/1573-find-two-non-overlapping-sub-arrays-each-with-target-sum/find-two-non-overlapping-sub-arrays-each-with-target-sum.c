typedef struct {
    int id;
    int pos;
    UT_hash_handle hh;
} HashEntry;

int minSumOfLengths(int* arr, int arrSize, int target) {
    int n = arrSize, s = 0, ans = n + 1, minL = n;
    HashEntry *prefixes = NULL, *entry, *tmp;
    entry = malloc(sizeof(HashEntry));
    entry->id = 0;
    entry->pos = -1;
    HASH_ADD_INT(prefixes, id, entry);

    for (int i = 0; i < n; i++) {
        s += arr[i];
        int key = s - target;
        HASH_FIND_INT(prefixes, &key, entry);
        if (entry != NULL) {
            int j = entry->pos, length = i - j;
            int prev = j == -1 ? n : arr[j];
            if (length + prev < ans) ans = length + prev;
            if (length < minL) minL = length;
        }
        arr[i] = minL;
        HASH_FIND_INT(prefixes, &s, entry);
        if (entry == NULL) {
            entry = malloc(sizeof(HashEntry));
            entry->id = s;
            HASH_ADD_INT(prefixes, id, entry);
        }
        entry->pos = i;
    }

    HASH_ITER(hh, prefixes, entry, tmp) {
        HASH_DEL(prefixes, entry);
        free(entry);
    }
    return ans == n + 1 ? -1 : ans;
}