#pragma GCC optimize("O3", "unroll-loops")
int compareVersion(char* v1, char* v2) {
    const char* dot = ".";
    char *token1, *token2;
    char *ptr1, *ptr2;
    token1 = strtok_r(v1, dot, &ptr1);
    token2 = strtok_r(v2, dot, &ptr2);
    while(token1 != NULL || token2 != NULL){
        int x1 = token1 != NULL ? atoi(token1) : 0;
        int x2 = token2 != NULL ? atoi(token2) : 0;
        if (x1 <x2) return -1;
        else if (x1 > x2) return 1;
        token1 = strtok_r(NULL, dot, &ptr1);
        token2 = strtok_r(NULL, dot, &ptr2);
    }
    return 0;
}