int countPermutations(int* complexity, int complexitySize) {
    int n = complexitySize;
    for (int i = 1; i < n; i++) {
        if (complexity[i] <= complexity[0]) {
            return 0;
        }
    }

    long long ans = 1;
    int mod = 1000000007;
    for (int i = 2; i < n; i++) {
        ans = ans * i % mod;
    }
    return (int)ans;
}