bool checkStrings(char* s1, char* s2) {
    int len = strlen(s1);
    if (len != strlen(s2)) {
        return false;
    }

    int counts[256] = {0};

    for (int i = 0; i < len; i++) {
        int offset = (i & 1) << 7;
        counts[offset + s1[i]]++;
        counts[offset + s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (counts[i] != 0) {
            return false;
        }
    }

    return true;
}