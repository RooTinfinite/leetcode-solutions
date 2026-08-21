long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int trailingZeros(int x) {
    int count = 0;
    while ((x & 1) == 0) {
        count++;
        x >>= 1;
    }
    return count;
}

int popcount(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

long long count(long long x, int m, long long* lcm) {
    long long res = 0;
    for (int mask = 1; mask < m; mask++) {
        if (lcm[mask] > x) continue;

        if (popcount(mask) & 1) {
            res += x / lcm[mask];
        } else {
            res -= x / lcm[mask];
        }
    }
    return res;
}

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

long long findKthSmallest(int* coins, int coinsSize, int k) {
    qsort(coins, coinsSize, sizeof(int), compare);
    int* newCoins = (int*)malloc(coinsSize * sizeof(int));
    int newSize = 0;
    for (int i = 0; i < coinsSize; i++) {
        int flag = 1;
        for (int j = 0; j < newSize; j++) {
            if (coins[i] % newCoins[j] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            newCoins[newSize++] = coins[i];
        }
    }

    int n = newSize;
    int m = 1 << n;
    long long* lcm = (long long*)malloc(m * sizeof(long long));
    long long l = k;
    long long r = (long long)newCoins[0] * k + 1;

    lcm[0] = 1;
    for (int mask = 1; mask < m; mask++) {
        int preMask = mask & (mask - 1);
        int i = trailingZeros(mask);

        long long tmp = lcm[preMask] / gcd(lcm[preMask], newCoins[i]);
        if (tmp <= r / newCoins[i]) {
            lcm[mask] = tmp * newCoins[i];
        } else {
            lcm[mask] = r + 1;
        }
    }

    while (l < r) {
        long long x = l + (r - l) / 2;
        if (count(x, m, lcm) >= k) {
            r = x;
        } else {
            l = x + 1;
        }
    }

    long long result = l;
    free(newCoins);
    free(lcm);
    return result;
}