class Solution {
    public int earliestFinishTime(int[] a, int[] b, int[] c, int[] d) {
        int ans = Integer.MAX_VALUE;
        // take land first

        int n = a.length;
        int minEnd = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            minEnd = Math.min(minEnd, a[i] + b[i]);
        }
        int m = c.length;

        for (int i = 0; i < m; i++) {
            ans = Math.min(ans, d[i] + Math.max(minEnd, c[i]));
        }

        // take water first
        minEnd = Integer.MAX_VALUE;
        for (int i = 0; i < m; i++) {
            minEnd = Math.min(minEnd, c[i] + d[i]);
        }

        for (int i = 0; i < n; i++) {
            ans = Math.min(ans, b[i] + Math.max(minEnd, a[i]));
        }

        return ans;
    }
}