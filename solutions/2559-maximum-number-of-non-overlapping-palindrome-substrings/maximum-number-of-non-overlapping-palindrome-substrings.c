bool check(char* s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) {
            return false;
        }
    }
    return true;
}

int maxPalindromes(char* s, int k) {
    int n = strlen(s);
    int ans = 0, start = 0;

    for (int r = k - 1; r < n; ++r) {
        int l = r - k + 1;
        if (l >= start && check(s, l, r)) {
            ++ans;
            start = r + 1;
            continue;
        }

        l = r - k;
        if (l >= start && check(s, l, r)) {
            ++ans;
            start = r + 1;
        }
    }

    return ans;
}