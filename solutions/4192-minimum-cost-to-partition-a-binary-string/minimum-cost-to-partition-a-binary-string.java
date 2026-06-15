class Solution {
    public long minCost(String s, int encCost, int flatCost) {
        int n_size = s.length();
        long[] pre = new long[n_size];
        pre[0] = (s.charAt(0) == '1') ? 1 : 0;
        for (int i = 1; i < n_size; i++) {
            pre[i] = pre[i - 1] + (s.charAt(i) == '1' ? 1 : 0);
        }
        
        return cost(0, n_size - 1, s, encCost, flatCost, pre);
    }

    private long cost(int l, int r, String s, int ec, int fc, long[] pre) {
        if (l > r) return (long) 1e18;
        
        long count = (l > 0) ? pre[r] - pre[l - 1] : pre[r];
        long keep = fc;
        long n = r - l + 1;
        
        if (count > 0) {
            keep = n * count * (long) ec;
        }
        
        long rcost = (long) 1e18;
        long lcost = (long) 1e18;
        
        if (n % 2 == 0) {
            int mid = l + (r - l) / 2;
            lcost = cost(l, mid, s, ec, fc, pre);
            rcost = cost(mid + 1, r, s, ec, fc, pre);
        }
        
        return Math.min(keep, rcost + lcost);
    }
}