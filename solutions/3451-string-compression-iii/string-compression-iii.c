#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compressedString(char* word) {
    int n = strlen(word);
    char* ans = (char*)malloc((2 * n + 1) * sizeof(char)); // Allocate memory for the result
    int ansIndex = 0;
    char prev = word[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (word[i] != prev) {
            ansIndex += sprintf(&ans[ansIndex], "%d%c", count, prev); // Append count and character to result
            prev = word[i];
            count = 1;
        } else {
            if (count == 9) { // Max count to avoid continuous characters beyond 9
                ansIndex += sprintf(&ans[ansIndex], "%d%c", count, prev);
                count = 1;
            } else {
                count++;
            }
        }
    }

    // Append the last group
    ansIndex += sprintf(&ans[ansIndex], "%d%c", count, prev);
    ans[ansIndex] = '\0'; // Null-terminate the string

    return ans;
}