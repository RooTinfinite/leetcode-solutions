class Solution {
    int[] h, ne, to, q;
    int idx;

    void add(int u, int v) {
        to[idx] = v; ne[idx] = h[u]; h[u] = idx++;
        to[idx] = u; ne[idx] = h[v]; h[v] = idx++;
    }

    int[] bfs(int s, int n) {
        int[] d = new int[n];
        for (int i = 0; i < n; i++) d[i] = -1;
        d[s] = 0;
        int head = 0, tail = 0;
        q[tail++] = s;
        while (head < tail) {
            int u = q[head++];
            for (int i = h[u]; i != -1; i = ne[i]) {
                int v = to[i];
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q[tail++] = v;
                }
            }
        }
        return d;
    }

    public int specialNodes(int n, int[][] edges, int x, int y, int z) {
        h = new int[n];
        for (int i = 0; i < n; i++) h[i] = -1;
        ne = new int[2 * n];
        to = new int[2 * n];
        q = new int[n];
        idx = 0;
        for (int[] e : edges) add(e[0], e[1]);

        int[] dx = bfs(x, n), dy = bfs(y, n), dz = bfs(z, n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long a = dx[i], b = dy[i], c = dz[i];
            long m = a > b ? (a > c ? a : c) : (b > c ? b : c);
            if (a * a + b * b + c * c == 2 * m * m) ans++;
        }
        return ans;
    }
}