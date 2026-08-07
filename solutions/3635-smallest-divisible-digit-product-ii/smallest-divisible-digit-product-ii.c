long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char* smallestNumber(char* num, long long t) {
    long long originalT = t;
    long long temp = t;
    for (int i = 2; i <= 9; i++) {
        while (temp % i == 0) {
            temp /= i;
        }
    }
    if (temp > 1) {
        char* result = (char*)malloc(3 * sizeof(char));
        strcpy(result, "-1");
        return result;
    }

    int n = strlen(num);
    long long* rem = (long long*)malloc((n + 1) * sizeof(long long));
    rem[0] = t;
    int pos = n - 1;

    char* numCopy = (char*)malloc((n + 1) * sizeof(char));
    strcpy(numCopy, num);

    for (int i = 0; i < n; i++) {
        if (numCopy[i] == '0') {
            pos = i;
            break;
        }
        rem[i + 1] = rem[i] / gcd(rem[i], numCopy[i] - '0');
    }

    if (rem[n] == 1) {
        free(rem);
        return numCopy;
    }

    for (int i = pos; i >= 0; i--) {
        while (++numCopy[i] <= '9') {
            long long tNow = rem[i] / gcd(rem[i], numCopy[i] - '0');
            int k = 9;

            for (int j = n - 1; j > i; j--) {
                while (tNow % k != 0) {
                    k--;
                }
                tNow /= k;
                numCopy[j] = '0' + k;
            }

            if (tNow == 1) {
                free(rem);
                return numCopy;
            }
        }
    }
    int factorCount = 0;
    long long tempT = originalT;
    for (int i = 9; i > 1; i--) {
        while (tempT % i == 0) {
            factorCount++;
            tempT /= i;
        }
    }

    int ansLen = factorCount;
    int padding = n + 1 - ansLen;
    if (padding > 0) {
        ansLen += padding;
    }

    char* ans = (char*)malloc((ansLen + 1) * sizeof(char));
    int idx = 0;
    tempT = originalT;

    for (int i = 9; i > 1; i--) {
        while (tempT % i == 0) {
            ans[idx++] = '0' + i;
            tempT /= i;
        }
    }

    for (int i = 0; i < padding; i++) {
        ans[idx++] = '1';
    }

    ans[idx] = '\0';

    for (int i = 0; i < idx / 2; i++) {
        char tempChar = ans[i];
        ans[i] = ans[idx - 1 - i];
        ans[idx - 1 - i] = tempChar;
    }

    free(rem);
    free(numCopy);
    return ans;
}