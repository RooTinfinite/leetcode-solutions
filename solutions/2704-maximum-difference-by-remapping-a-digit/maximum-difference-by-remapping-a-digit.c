int minMaxDifference(int num) {
    char s[16], t[16];
    sprintf(s, "%d", num);
    strcpy(t, s);
    int pos = 0;
    while (s[pos] != '\0' && s[pos] == '9') {
        pos++;
    }
    if (s[pos] != '\0') {
        char a = s[pos];
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == a) {
                s[i] = '9';
            }
        }
    }
    char b = t[0];
    for (int i = 0; t[i] != '\0'; i++) {
        if (t[i] == b) {
            t[i] = '0';
        }
    }
    return atoi(s) - atoi(t);
}