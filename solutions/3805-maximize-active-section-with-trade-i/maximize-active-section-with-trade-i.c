int maxActiveSectionsAfterTrade(char* s) {
    int n = strlen(s);
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt1++;
        }
    }

    int i = 0;
    int bestGain = 0;
    int prev = INT_MIN;
    int cur = 0;

    while (i < n) {
        int start = i;
        while (i < n && s[i] == s[start]) {
            i++;
        }
        if (s[start] == '0') {
            cur = i - start;
            if (prev != INT_MIN) {
                bestGain = (prev + cur > bestGain) ? prev + cur : bestGain;
            }
            prev = cur;
        }
    }

    return cnt1 + bestGain;
}