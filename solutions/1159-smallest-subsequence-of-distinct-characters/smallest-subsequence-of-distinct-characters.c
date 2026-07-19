char* smallestSubsequence(char* s) {
    int vis[26], num[26];
    memset(vis, 0, sizeof(vis));
    memset(num, 0, sizeof(num));

    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        num[s[i] - 'a']++;
    }

    char* stk = malloc(sizeof(char) * 27);
    int stkTop = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[s[i] - 'a']) {
            while (stkTop > 0 && stk[stkTop - 1] > s[i]) {
                if (num[stk[stkTop - 1] - 'a'] > 0) {
                    vis[stk[--stkTop] - 'a'] = 0;
                } else {
                    break;
                }
            }
            vis[s[i] - 'a'] = 1;
            stk[stkTop++] = s[i];
        }
        num[s[i] - 'a'] -= 1;
    }
    stk[stkTop] = '\0';
    return stk;
}