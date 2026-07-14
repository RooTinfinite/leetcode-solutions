#define MOD 1000000007

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int subsequencePairCount(int* nums, int numsSize) {
    int m = 0;
    for (int i = 0; i < numsSize; i++) {
        m = fmax(m, nums[i]);
    }

    int dp[m + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int ndp[m + 1][m + 1];
        memset(ndp, 0, sizeof(ndp));

        for (int j = 0; j <= m; j++) {
            int divisor1 = gcd(j, num);
            for (int k = 0; k <= m; k++) {
                int val = dp[j][k];
                if (val == 0) {
                    continue;
                }
                int divisor2 = gcd(k, num);
                ndp[j][k] = (ndp[j][k] + val) % MOD;
                ndp[divisor1][k] = (ndp[divisor1][k] + val) % MOD;
                ndp[j][divisor2] = (ndp[j][divisor2] + val) % MOD;
            }
        }

        memcpy(dp, ndp, sizeof(ndp));
    }

    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = (ans + dp[j][j]) % MOD;
    }

    return ans;
}