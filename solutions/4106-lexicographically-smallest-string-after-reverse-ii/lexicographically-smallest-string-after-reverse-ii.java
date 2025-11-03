class Solution {
    // time = O(nlogn), space = O(n)
    final long mod1 = (long)1E9 + 7, mod2 = (long)1E9 + 9, P = 131;
    int n;
    String s, t;
    long[] p1, p2;
    long[] hs1, hs2, ht1, ht2;
    public String lexSmallest(String s) {
        this.s = s;
        n = s.length();
        t = new StringBuilder(s).reverse().toString();

        build();
        int bk = 1, bo = 0;
        for (int k = 1; k <= n; k++) {
            if (check(k, 0, bk, bo)) {
                bk = k;
                bo = 0;
            }
            if (check(k, 1, bk, bo)) {
                bk = k;
                bo = 1;
            }
        }
        return bo == 0 ? t.substring(n - bk) + s.substring(bk) : s.substring(0, n - bk) + t.substring(0, bk);
    }

    private boolean check(int k1, int op1, int k2, int op2) {
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (checkPrefix(k1, op1, k2, op2, mid)) l = mid;
            else r = mid - 1;
        }
        int lcp = r;
        if (lcp == n) return false;
        char c1 = getChar(k1, op1, lcp), c2 = getChar(k2, op2, lcp);
        return c1 < c2;
    }

    private boolean checkPrefix(int k1, int op1, int k2, int op2, int len) {
        if (len == 0) return true;
        long[] a = get(k1, op1, 0, len - 1);
        long[] b = get(k2, op2, 0, len - 1);
        return a[0] == b[0] && a[1] == b[1];
    }

    private char getChar(int k, int op, int idx) {
        if (op == 0) return idx < k ? t.charAt(n - k + idx) : s.charAt(idx);
        int split = n - k;
        return idx < split ? s.charAt(idx) : t.charAt(idx - split);
    }

    private long[] subHashS(int l, int r) {
        l++;
        r++;
        long v1 = ((hs1[r] - hs1[l - 1] * p1[r - l + 1]) % mod1 + mod1) % mod1;
        long v2 = ((hs2[r] - hs2[l - 1] * p2[r - l + 1]) % mod2 + mod2) % mod2;
        return new long[]{v1, v2};
    }

    private long[] subHashT(int l, int r) {
        l++;
        r++;
        long v1 = ((ht1[r] - ht1[l - 1] * p1[r - l + 1]) % mod1 + mod1) % mod1;
        long v2 = ((ht2[r] - ht2[l - 1] * p2[r - l + 1]) % mod2 + mod2) % mod2;
        return new long[]{v1, v2};
    }

    private long[] get(int k, int op, int l, int r) {
        if (l > r) return new long[0];
        if (op == 0) {
            if (r < k) return subHashT(n - k + l, n - k + r);
            if (l >= k) return subHashS(l, r);
            long[] h1 = subHashT(n - k + l, n - 1);
            long[] h2 = subHashS(k, r);
            int len2 = r - k + 1;
            long v1 = (h1[0] * p1[len2] + h2[0]) % mod1;
            long v2 = (h1[1] * p2[len2] + h2[1]) % mod2;
            return new long[]{v1, v2};
        } else {
            int split = n - k;
            if (r < split) return subHashS(l, r);
            if (l >= split) return subHashT(l - split, r - split);
            long[] h1 = subHashS(l, split - 1);
            long[] h2 = subHashT(0, r - split);
            int len2 = r - split + 1;
            long v1 = (h1[0] * p1[len2] + h2[0]) % mod1;
            long v2 = (h1[1] * p2[len2] + h2[1]) % mod2;
            return new long[]{v1, v2};
        }
    }

    private void build() {
        p1 = new long[n + 1];
        p2 = new long[n + 1];
        p1[0] = p2[0] = 1;
        for (int i = 1; i <= n; i++) {
            p1[i] = p1[i - 1] * P % mod1;
            p2[i] = p2[i - 1] * P % mod2;
        }
        hs1 = new long[n + 1];
        hs2 = new long[n + 1];
        ht1 = new long[n + 1];
        ht2 = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            int cs = s.charAt(i - 1), ct = t.charAt(i - 1);
            hs1[i] = (hs1[i - 1] * P + cs) % mod1;
            hs2[i] = (hs2[i - 1] * P + cs) % mod2;
            ht1[i] = (ht1[i - 1] * P + ct) % mod1;
            ht2[i] = (ht2[i - 1] * P + ct) % mod2;
        }
    }
}