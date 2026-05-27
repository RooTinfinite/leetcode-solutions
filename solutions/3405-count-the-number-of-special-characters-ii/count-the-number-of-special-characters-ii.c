int numberOfSpecialChars(char* word) {
    int lastLow[26], firstUp[26];
    memset(lastLow, -1, sizeof(lastLow));
    memset(firstUp, -1, sizeof(firstUp));
    for (int i = 0; word[i]; i++) {
        char c = word[i];
        if (c >= 'a' && c <= 'z') {
            lastLow[c - 'a'] = i;
        } else {
            if (firstUp[c - 'A'] == -1) {
                firstUp[c - 'A'] = i;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (lastLow[i] != -1 && firstUp[i] != -1 && lastLow[i] < firstUp[i]) {
            ans++;
        }
    }
    return ans;
}