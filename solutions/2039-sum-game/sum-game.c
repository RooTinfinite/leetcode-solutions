void get(char* s, int len, int* sum, int* count) {
    *sum = 0;
    *count = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '?') {
            (*count)++;
        } else {
            *sum += (s[i] - '0');
        }
    }
}

bool sumGame(char* num) {
    int n = strlen(num);
    int half = n / 2;
    int n0, q0, n1, q1;

    char left[half + 1];
    strncpy(left, num, half);
    left[half] = '\0';
    get(left, half, &n0, &q0);
    get(num + half, half, &n1, &q1);

    return ((q0 + q1) % 2 == 1) || (n0 - n1 != (q1 - q0) * 9 / 2);
}