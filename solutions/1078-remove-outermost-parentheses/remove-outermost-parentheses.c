char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    int level = 0;
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    int pos = 0;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == ')') {
            level--;
        }
        if (level > 0) {
            res[pos++] = c;
        }
        if (c == '(') {
            level++;
        }
    }
    res[pos] = '\0';
    return res;
}