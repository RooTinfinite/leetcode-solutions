typedef struct {
    char* key;
    char* val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, const char* key) {
    HashItem* pEntry = NULL;
    HASH_FIND_STR(*obj, key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, char* key, char* val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem** obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

char* evaluate(char* s, char*** knowledge, int knowledgeSize,
               int* knowledgeColSize) {
    HashItem* dict = NULL;
    for (int i = 0; i < knowledgeSize; i++) {
        hashAddItem(&dict, knowledge[i][0], knowledge[i][1]);
    }
    bool addKey = false;
    int len = strlen(s);
    int maxResLen = (len / 3 + 1) * 10 + len + 1;
    char key[16], *res = (char*)malloc(sizeof(char) * maxResLen);
    int keySize = 0, resSize = 0;
    memset(key, 0, sizeof(key));
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(') {
            addKey = true;
        } else if (c == ')') {
            HashItem* pEntry = hashFindItem(&dict, key);
            if (pEntry) {
                resSize += sprintf(res + resSize, "%s", pEntry->val);
            } else {
                res[resSize++] = '?';
            }
            addKey = false;
            keySize = 0;
        } else if (addKey) {
            if (keySize < sizeof(key) - 1) {
                key[keySize++] = c;
                key[keySize] = '\0';
            }
        } else {
            res[resSize++] = c;
        }
    }
    hashFree(&dict);
    res[resSize] = '\0';
    return res;
}