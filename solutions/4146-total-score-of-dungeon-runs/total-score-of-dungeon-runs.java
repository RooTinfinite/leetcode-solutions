class Fenwick {
    long[] bit;
    int n;

    Fenwick(int n) {
        this.n = n;
        bit = new long[n + 1];
    }

    void add(int i, int v) {
        for( ; i <= n; i += i & -i) bit[i] += v;
    }
    long sum(int i) {
        long s = 0;
        for(; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
}

class Solution {
    public long totalScore(int hp, int[] d, int[] r) {
        int n = d.length;
        long[] pref = new long[n + 1];
        for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + d[i - 1];
        long[] all = new long[2 * (n + 1)];
        int idx = 0;
        for(int i = 0; i <= n; i++) all[idx++] = pref[i];
        for(int i = 1; i <= n; i++) {
            long need = pref[i] + r[i - 1] - hp;
            all[idx++] = need;
        }
        Arrays.sort(all);
        idx = fun(all, idx);
        
        Fenwick f = new Fenwick(idx + 5);
        f.add(lower(all, pref[0], idx), 1);

        long sum = 0;
        for(int i = 1; i <= n; i++) {
            long need = pref[i] + r[i - 1] - hp;
            int pos = lower(all, need, idx);
            long valid = f.sum(idx) - f.sum(pos - 1);
            sum += valid;
            f.add(lower(all, pref[i], idx), 1);
        }
        return sum;
    }
    int fun(long[] a, int n) {
        if(n == 0) return 0;
        int k = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] != a[k - 1]) a[k++] = a[i];
        }
        return k;
    }
    int lower(long[] a, long x, int n) {
        int l = 0, r = n;
        while(l < r) {
            int m = (l + r) >>> 1;
            if(a[m] < x) l = m + 1;
            else r = m;
        }
        return l + 1;
    }
}