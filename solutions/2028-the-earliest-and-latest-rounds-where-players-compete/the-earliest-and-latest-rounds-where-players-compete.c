int F[30][30][30] = {0};
int G[30][30][30] = {0};

void dp(int n, int f, int s, int* earliest, int* latest) {
    if (F[n][f][s]) {
        *earliest = F[n][f][s];
        *latest = G[n][f][s];
        return;
    }
    if (f + s == n + 1) {
        *earliest = 1;
        *latest = 1;
        return;
    }

    // F(n,f,s) = F(n,n+1-s,n+1-f)
    if (f + s > n + 1) {
        int x, y;
        dp(n, n + 1 - s, n + 1 - f, &x, &y);
        F[n][f][s] = x;
        G[n][f][s] = y;
        *earliest = x;
        *latest = y;
        return;
    }

    int min_earliest = INT_MAX;
    int max_latest = INT_MIN;
    int n_half = (n + 1) / 2;

    if (s <= n_half) {
        // On the left or in the middle
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < s - f; ++j) {
                int x, y;
                dp(n_half, i + 1, i + j + 2, &x, &y);
                if (x < min_earliest) {
                    min_earliest = x;
                }
                if (y > max_latest) {
                    max_latest = y;
                }
            }
        }
    } else {
        // s on the right
        int s_prime = n + 1 - s;
        int mid = (n - 2 * s_prime + 1) / 2;
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < s_prime - f; ++j) {
                int x, y;
                dp(n_half, i + 1, i + j + mid + 2, &x, &y);
                if (x < min_earliest) {
                    min_earliest = x;
                }
                if (y > max_latest) {
                    max_latest = y;
                }
            }
        }
    }

    F[n][f][s] = min_earliest + 1;
    G[n][f][s] = max_latest + 1;
    *earliest = F[n][f][s];
    *latest = G[n][f][s];
}

int* earliestAndLatest(int n, int firstPlayer, int secondPlayer,
                       int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    // F(n,f,s) = F(n,s,f)
    if (firstPlayer > secondPlayer) {
        int temp = firstPlayer;
        firstPlayer = secondPlayer;
        secondPlayer = temp;
    }

    int earliest, latest;
    dp(n, firstPlayer, secondPlayer, &earliest, &latest);
    result[0] = earliest;
    result[1] = latest;
    return result;
}