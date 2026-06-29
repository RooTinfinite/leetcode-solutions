bool check(const char* pattern, const char* word) {
    int m = strlen(pattern);
    int n = strlen(word);

    // generate the prefix array of the pattern
    int* pi = (int*)malloc(m * sizeof(int));
    pi[0] = 0;
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        pi[i] = j;
    }

    // using prefix arrays for matching
    bool found = false;
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && word[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (word[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            found = true;
            break;
        }
    }

    free(pi);
    return found;
}

int numOfStrings(char** patterns, int patternsSize, char* word) {
    int res = 0;
    for (int i = 0; i < patternsSize; i++) {
        if (check(patterns[i], word)) {
            res++;
        }
    }
    return res;
}