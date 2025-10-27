// include the utash.h
struct letters {
    char id; /* key */
    const char* value;
    UT_hash_handle hh; /* makes this structure hashable */
};
void backtrack(struct letters** lettersHash, const char* digits, int index,
               char* path, int pathLen, char** combinations, int* returnSize) {
    if (pathLen == strlen(digits)) {
        path[pathLen] = '\0';
        combinations[*returnSize] = (char*)calloc(pathLen + 1, sizeof(char));
        strncpy(combinations[*returnSize], path, pathLen + 1);
        (*returnSize)++;
        return;
    }
    struct letters* s;
    HASH_FIND(hh, *lettersHash, &digits[index], sizeof(char), s);
    const char* possibleLetters = s->value;
    while (*possibleLetters) {
        path[pathLen] = *possibleLetters;
        backtrack(lettersHash, digits, index + 1, path, pathLen + 1,
                  combinations, returnSize);
        possibleLetters++;
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }
    struct letters m1 = {'2', "abc"}, m2 = {'3', "def"}, m3 = {'4', "ghi"},
                   m4 = {'5', "jkl"}, m5 = {'6', "mno"}, m6 = {'7', "pqrs"},
                   m7 = {'8', "tuv"}, m8 = {'9', "wxyz"}, *s,
                   *lettersHash = NULL;
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m1);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m2);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m3);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m4);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m5);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m6);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m7);
    HASH_ADD(hh, lettersHash, id, sizeof(char), &m8);
    char** combinations = (char**)malloc(1024 * sizeof(char*));
    char* path = (char*)calloc(5, sizeof(char));
    *returnSize = 0;
    backtrack(&lettersHash, digits, 0, path, 0, combinations, returnSize);
    free(path);
    HASH_CLEAR(hh, lettersHash);
    return combinations;
}