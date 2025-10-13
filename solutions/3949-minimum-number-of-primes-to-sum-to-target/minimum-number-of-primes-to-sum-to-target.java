class Solution {
    // time = O(n^2), space = O(n)
    final int inf = 0x3f3f3f3f;
    int[] primes;
    boolean[] st;
    int cnt;
    public int minNumberOfPrimes(int n, int m) {
        primes = new int[n + 1];
        st = new boolean[n + 1];
        get_primes(n);
        int[] f = new int[n + 1];
        Arrays.fill(f, inf);
        f[0] = 0;
        for (int i = 0; i < Math.min(m, cnt); i++) {
            for (int j = primes[i]; j <= n; j++) {
                f[j] = Math.min(f[j], f[j - primes[i]] + 1);
            }
        }
        return f[n] == inf ? -1 : f[n];
    }

    private void get_primes(int n) {
        for (int i = 2; i <= n; i++) {
            if (!st[i]) primes[cnt++] = i;
            for (int j = 0; i * primes[j] <= n; j++) {
                st[i * primes[j]] = true;
                if (i % primes[j] == 0) break;
            }
        }
    }
}