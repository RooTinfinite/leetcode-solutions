struct Element {
    int index;
    char char_val;
};
char* minWindow(char* s, char* t) {
    if (strlen(s) == 0 || strlen(t) == 0) {
        return "";
    }
    struct HashT {
        char id;
        int count;
        UT_hash_handle hh;
    };
    struct HashT *dictT = NULL, *el, *tmp, *windowCounts = NULL;
    for (int i = 0; i < strlen(t); i++) {
        HASH_FIND(hh, dictT, &(t[i]), sizeof(char), tmp);
        if (tmp) {
            tmp->count++;
        } else {
            tmp = (struct HashT*)malloc(sizeof *tmp);
            tmp->id = t[i];
            tmp->count = 1;
            HASH_ADD(hh, dictT, id, sizeof(char), tmp);
        }
    }
    int required = HASH_COUNT(dictT);
    struct Element* filteredS =
        (struct Element*)malloc(strlen(s) * sizeof(struct Element));
    int filteredSCount = 0;
    for (int i = 0; i < strlen(s); i++) {
        HASH_FIND(hh, dictT, &(s[i]), sizeof(char), tmp);
        if (tmp) {
            filteredS[filteredSCount].index = i;
            filteredS[filteredSCount].char_val = s[i];
            filteredSCount++;
        }
    }
    int l = 0, r = 0, formed = 0, ans[3] = {-1, 0, 0};
    while (r < filteredSCount) {
        char c = filteredS[r].char_val;
        HASH_FIND(hh, windowCounts, &c, sizeof(char), tmp);
        if (tmp) {
            tmp->count++;
        } else {
            tmp = (struct HashT*)malloc(sizeof *tmp);
            tmp->id = c;
            tmp->count = 1;
            HASH_ADD(hh, windowCounts, id, sizeof(char), tmp);
        }
        HASH_FIND(hh, dictT, &c, sizeof(char), el);
        if (el && tmp->count == el->count) {
            formed++;
        }
        while (l <= r && formed == required) {
            c = filteredS[l].char_val;
            int end = filteredS[r].index;
            int start = filteredS[l].index;
            if (ans[0] == -1 || end - start + 1 < ans[0]) {
                ans[0] = end - start + 1;
                ans[1] = start;
                ans[2] = end;
            }
            HASH_FIND(hh, windowCounts, &c, sizeof(char), tmp);
            if (tmp) {
                tmp->count--;
            }
            HASH_FIND(hh, dictT, &c, sizeof(char), el);
            if (el && tmp->count < el->count) {
                formed--;
            }
            l++;
        }
        r++;
    }
    return ans[0] == -1 ? "" : strndup(s + ans[1], ans[0]);
}