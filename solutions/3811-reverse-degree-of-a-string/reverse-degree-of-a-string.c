int reverseDegree(char* s) {
    int ans = 0;
    int len = strlen(s);
    for (int i = 1; i <= len; i++) {
        ans += (26 - (s[i - 1] - 'a')) * i;
    }
    return ans;
}