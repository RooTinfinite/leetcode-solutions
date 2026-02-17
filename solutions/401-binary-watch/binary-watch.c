char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** ans = malloc(sizeof(char*) * 12 * 60);
    *returnSize = 0;
    for (int h = 0; h < 12; ++h) {
        for (int m = 0; m < 60; ++m) {
            if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                char* tmp = malloc(sizeof(char) * 6);
                sprintf(tmp, "%d:%02d", h, m);
                ans[(*returnSize)++] = tmp;
            }
        }
    }
    return ans;
}