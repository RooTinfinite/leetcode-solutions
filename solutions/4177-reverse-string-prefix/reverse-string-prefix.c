#include <string.h>

char* reversePrefix(char* s, int k) {
    int i = 0;
    k = k - 1;

    while (i < k) {
        char temp = s[i];
        s[i] = s[k];
        s[k] = temp;
        i++;
        k--;
    }
    return s;
}