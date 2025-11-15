int numberOfSubstrings(char* s) {
    int n = strlen(s);
    int* pre = (int*)malloc((n + 1) * sizeof(int));
    pre[0] = -1;
    for (int i = 0; i < n; i++) {
        if (i == 0 || (i > 0 && s[i - 1] == '0')) {
            pre[i + 1] = i;
        } else {
            pre[i + 1] = pre[i];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int cnt0 = s[i - 1] == '0' ? 1 : 0;
        int j = i;
        while (j > 0 && cnt0 * cnt0 <= n) {
            int cnt1 = (i - pre[j]) - cnt0;
            if (cnt0 * cnt0 <= cnt1) {
                int add = j - pre[j];
                if (cnt1 - cnt0 * cnt0 + 1 < add) {
                    add = cnt1 - cnt0 * cnt0 + 1;
                }
                res += add;
            }
            j = pre[j];
            cnt0++;
        }
    }
    free(pre);
    return res;
}