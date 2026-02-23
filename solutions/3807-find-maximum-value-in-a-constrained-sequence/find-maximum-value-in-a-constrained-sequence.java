class Solution {
    public int findMaxVal(int n, int[][] restrictions, int[] diff) {
        long[] a = new long[n];
        Arrays.fill(a, Long.MAX_VALUE/2);
        a[0] = 0;
        for(int[] r : restrictions) {
            int idx = r[0];
            int maxL = r[1];
            a[idx] = Math.min(a[idx], (long)maxL);
        }
        for(int i = 1; i < n; ++i)
            a[i] = Math.min(a[i], a[i - 1] + diff[i - 1]);
        for(int i = n - 2; i >= 0; --i)
            a[i] = Math.min(a[i], a[i + 1] + diff[i]);
        long ans = 0;
        for(long v : a)
            ans = Math.max(ans, v);
        return (int) ans;
    }
}