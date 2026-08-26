char* shortestBeautifulSubstring(char* s, int k) {
    static char ans[105], t[105];
    int n = strlen(s);
    for (int m = k; m <= n; m++) {
        ans[0] = '\0';
        for (int i = m; i <= n; i++) {
            int cnt = 0;
            for (int j = i - m; j < i; j++) {
                cnt += s[j] - '0';
            }
            if (cnt == k) {
                memcpy(t, s + i - m, m);
                t[m] = '\0';
                if (ans[0] == '\0' || strcmp(t, ans) < 0) {
                    strcpy(ans, t);
                }
            }
        }
        if (ans[0] != '\0') {
            return ans;
        }
    }
    ans[0] = '\0';
    return ans;
}