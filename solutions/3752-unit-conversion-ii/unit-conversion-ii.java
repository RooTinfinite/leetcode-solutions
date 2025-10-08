class Solution {
    // time = O(n + m), space = O(n)
    long mod = (long)(1e9 + 7);
    List<long[]>[] adj;
    long[] d, ind;
    boolean[] st;
    public int[] queryConversions(int[][] conversions, int[][] queries) {
        int n = conversions.length + 1;
        adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for (int[] x : conversions) {
            int a = x[0], b = x[1], c = x[2];
            long inv = qmi(c, mod - 2);
            adj[a].add(new long[]{b, c, inv});
            adj[b].add(new long[]{a, inv, c});
        }

        d = new long[n];
        ind = new long[n];
        st = new boolean[n];
        d[0] = 1;
        ind[0] = 1;
        dfs(0);

        int m = queries.length;
        int[] res = new int[m];
        for (int i = 0; i < m; i++) {
            int a = queries[i][0], b = queries[i][1];
            res[i] = (int)(d[b] * ind[a] % mod);
        }
        return res;
    }

    private void dfs(int u) {
        st[u] = true;
        for (long[] x : adj[u]) {
            int v = (int)x[0];
            if (st[v]) continue;
            long a = x[1], b = x[2];
            d[v] = d[u] * a % mod;
            ind[v] = ind[u] * b % mod;
            dfs(v);
        }
    }

    private long qmi(long a, long k) {
        long res = 1;
        while (k > 0) {
            if ((k & 1) == 1) res = res * a % mod;
            a = a * a % mod;
            k >>= 1;
        }
        return res;
    }
}