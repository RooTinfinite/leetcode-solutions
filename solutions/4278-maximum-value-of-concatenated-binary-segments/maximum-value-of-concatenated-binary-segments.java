class Solution {
    static final long MOD = 1_000_000_007L;

    long find(long base, long exp) {
        long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = res * base % MOD;
            base = base * base % MOD;
            exp /= 2;
        }
        return res;
    }

    public int maxValue(int[] nums1, int[] nums0) {
        int n = nums1.length;
        List<int[]> a = new ArrayList<>();
        int last = 0;

        for (int i = 0; i < n; i++) {
            if (nums0[i] == 0) {
                last += nums1[i];
            } else {
                a.add(new int[]{nums1[i], nums0[i]});
            }
        }

        a.sort((x, y) -> x[0] != y[0] ? y[0] - x[0] : x[1] - y[1]);

        long ans = 0;
        long exp = 0;

        for (int i = a.size() - 1; i >= 0; i--) {
            int one = a.get(i)[0];
            int zero = a.get(i)[1];
            exp += zero;
            long first = find(2, exp);
            long rn = find(2, one);
            long val = first * ((rn - 1 + MOD) % MOD) % MOD;
            ans = (ans + val) % MOD;
            exp += one;
        }

        long first = find(2, exp);
        long rn = find(2, last);
        long val = first * ((rn - 1 + MOD) % MOD) % MOD;
        ans = (ans + val) % MOD;

        return (int) ans;
    }
}