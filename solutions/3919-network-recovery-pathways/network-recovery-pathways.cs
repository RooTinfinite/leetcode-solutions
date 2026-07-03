public class Solution {
    public int FindMaxPathScore(int[][] edges, bool[] online, long k) {
        int n = online.Length;
        var g = new List<(int, int)>[n];
        var deg = new int[n];
        for (int i = 0; i < n; i++) {
            g[i] = new List<(int, int)>();
        }

        int l = int.MaxValue, r = 0;
        foreach (var edge in edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (!online[u] || !online[v]) {
                continue;
            }
            g[u].Add((v, w));
            deg[v]++;
            l = Math.Min(l, w);
            r = Math.Max(r, w);
        }

        // Delete unreachable nodes
        var q = new Queue<int>();
        for (int i = 1; i < n; i++) {
            if (deg[i] == 0) {
                q.Enqueue(i);
            }
        }
        while (q.Count > 0) {
            int u = q.Dequeue();
            foreach (var (v, _) in g[u]) {
                if (--deg[v] == 0 && v != 0) {
                    q.Enqueue(v);
                }
            }
        }

        if (!Check(l, k, g, deg, n)) {
            return -1;
        }

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (Check(mid, k, g, deg, n)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }

    private bool Check(int mid, long k, List<(int, int)>[] g, int[] deg,
                       int n) {
        var dp = new long[n];
        Array.Fill(dp, long.MaxValue / 2);
        var cdeg = (int[])deg.Clone();
        dp[0] = 0;

        var q = new Queue<int>();
        q.Enqueue(0);

        while (q.Count > 0) {
            int u = q.Dequeue();
            if (u == n - 1) {
                return dp[u] <= k;
            }

            foreach (var (v, w) in g[u]) {
                if (w >= mid) {
                    dp[v] = Math.Min(dp[v], dp[u] + w);
                }
                if (--cdeg[v] == 0) {
                    q.Enqueue(v);
                }
            }
        }
        return false;
    }
}