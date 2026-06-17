char processStr(char* s, long long k) {
    long long len = 0;
    size_t n = strlen(s);
    for (size_t i = 0; i < n; i++) {
        char c = s[i];
        if (c == '*') {
            if (len > 0) {
                len--;
            }
        } else if (c == '#') {
            len *= 2;
        } else if (c == '%') {
            ;
        } else {
            len++;
        }
    }
    if (k + 1 > len) {
        return '.';
    }
    for (long long i = (long long)n - 1; i >= 0; i--) {
        char c = s[i];
        if (c == '*') {
            len++;
        } else if (c == '#') {
            if (k + 1 > (len + 1) / 2) {
                k -= len / 2;
            }
            len = (len + 1) / 2;
        } else if (c == '%') {
            k = len - k - 1;
        } else {
            if (k + 1 == len) {
                return c;
            }
            len--;
        }
    }
    return '.';
}