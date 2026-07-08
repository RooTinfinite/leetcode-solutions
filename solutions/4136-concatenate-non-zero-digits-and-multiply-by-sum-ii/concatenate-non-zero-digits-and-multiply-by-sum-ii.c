#define MAX_N 100005
static long long pow10[MAX_N];
static bool initialized = false;

void init_pow10() {
    if (initialized) return;
    long long MOD = 1000000007;
    pow10[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }
    initialized = true;
}

int* sumAndMultiply(char* s, int** queries, int queriesSize,
                    int* queriesColSize, int* returnSize) {
    init_pow10();
    int n = strlen(s);
    long long MOD = 1000000007;
    int* sum = (int*)calloc(n + 1, sizeof(int));
    long long* x = (long long*)calloc(n + 1, sizeof(long long));
    int* cnt = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i < n; ++i) {
        int d = s[i] - '0';
        sum[i + 1] = sum[i] + d;
        x[i + 1] = (d > 0) ? (x[i] * 10 + d) % MOD : x[i];
        cnt[i + 1] = cnt[i] + (d > 0);
    }
    int m = queriesSize;
    int* res = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i) {
        int l = queries[i][0];
        int r = queries[i][1] + 1;
        int length = cnt[r] - cnt[l];
        long long val_x = (x[r] - x[l] * pow10[length] % MOD + MOD) % MOD;
        long long val_sum = sum[r] - sum[l];
        res[i] = (int)((val_x * val_sum) % MOD);
    }
    free(sum);
    free(x);
    free(cnt);
    *returnSize = m;
    return res;
}