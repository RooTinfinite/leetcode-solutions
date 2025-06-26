int longestSubsequence(char* s, int k) {
    int sm = 0;
    int cnt = 0;
    int bits = (int)(log2(k)) + 1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char ch = s[len - 1 - i];
        if (ch == '1') {
            if (i < bits && sm + (1 << i) <= k) {
                sm += 1 << i;
                cnt++;
            }
        } else {
            cnt++;
        }
    }
    return cnt;
}