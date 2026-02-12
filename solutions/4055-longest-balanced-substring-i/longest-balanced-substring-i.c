int longestBalanced(char* s) {
    int n = strlen(s);
    int res = 0;
    int cnt[26];

    for (int i = 0; i < n; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j < n; j++) {
            bool flag = true;
            int c = s[j] - 'a';
            cnt[c]++;

            for (int k = 0; k < 26; k++) {
                if (cnt[k] > 0 && cnt[k] != cnt[c]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                int length = j - i + 1;
                if (length > res) {
                    res = length;
                }
            }
        }
    }
    return res;
}