#include <string.h>
#include <stdlib.h>

char* largestEven(char* s) {
    int len = strlen(s);
    int ind = -1;

    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '2') {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        char* res = (char*)malloc(1);
        res[0] = '\0';
        return res;
    }

    char* res = (char*)malloc(ind + 2);
    strncpy(res, s, ind + 1);
    res[ind + 1] = '\0';
    return res;
}