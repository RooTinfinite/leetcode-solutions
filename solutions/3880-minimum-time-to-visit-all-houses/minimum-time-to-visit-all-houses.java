class Solution {
    public long minTotalTime(int[] forward, int[] backward, int[] queries) {
        int n = forward.length;
        long[] fwd = new long[n+1], bwd = new long[n+1];
        for (int i = 1; i <= n; i++) {
            fwd[i] = fwd[i-1] + forward[i-1];
            bwd[i] = bwd[i-1] + (i < n ? backward[i] : backward[0]);
        }
        long res = 0;
        int cur = 0;
        for (int q : queries) {
            int u = cur, v = q;
            long cw = u <= v
                ? fwd[v] - fwd[u]
                : fwd[n] - (fwd[u] - fwd[v]);
            long ccw = u >= v
                ? bwd[u] - bwd[v]
                : bwd[n] - (bwd[v] - bwd[u]);
            res += Math.min(cw, ccw);
            cur = v;
        }
        return res;
    }
}