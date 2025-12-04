int countCollisions(char* directions) {
    int res = 0;
    int flag = -1;

    for (int i = 0; directions[i] != '\0'; i++) {
        char c = directions[i];
        if (c == 'L') {
            if (flag >= 0) {
                res += flag + 1;
                flag = 0;
            }
        } else if (c == 'S') {
            if (flag > 0) {
                res += flag;
            }
            flag = 0;
        } else {
            if (flag >= 0) {
                flag++;
            } else {
                flag = 1;
            }
        }
    }
    return res;
}