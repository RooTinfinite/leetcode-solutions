int distinctSubseqII(char* s) {
    const int MOD = 1000000007;

    long long count[26] = {0};
    long long sum = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        long long total = (1 + sum) % MOD;
        int idx = s[i] - 'a';

        sum = (sum + total - count[idx] + MOD) % MOD;
        count[idx] = total;
    }

    return (int)sum;
}