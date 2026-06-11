public class Solution {
    private const int MOD = 1_000_000_007;

    private int QPow(int x, int y) {
        long res = 1;
        long baseVal = x;
        while (y > 0) {
            if ((y & 1) == 1) {
                res = (res * baseVal) % MOD;
            }
            baseVal = (baseVal * baseVal) % MOD;
            y >>= 1;
        }
        return (int)res;
    }

    private int Dfs(List<List<int>> g, int x, int f) {
        int maxDep = 0;
        foreach (int y in g[x]) {
            if (y == f)
                continue;
            maxDep = System.Math.Max(maxDep, Dfs(g, y, x) + 1);
        }
        return maxDep;
    }

    public int AssignEdgeWeights(int[][] edges) {
        int n = edges.Length + 1;
        var g = new List<List<int>>();
        for (int i = 0; i <= n; i++) {
            g.Add(new List<int>());
        }
        foreach (var e in edges) {
            int u = e[0];
            int v = e[1];
            g[u].Add(v);
            g[v].Add(u);
        }
        int maxDep = Dfs(g, 1, 0);
        return QPow(2, maxDep - 1);
    }
}