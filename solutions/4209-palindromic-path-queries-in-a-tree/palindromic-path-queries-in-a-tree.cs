class BIT {
    private int[] tree;
    private int n;

    public BIT(int _n) {
        n = _n;
        tree = new int[_n + 1];
    }

    private static int Lowbit(int x) => x & -x;

    public void Update(int x, int v) {
        while (x <= n) {
            tree[x] ^= v;
            x += Lowbit(x);
        }
    }

    public int Query(int x) {
        int ret = 0;
        while (x > 0) {
            ret ^= tree[x];
            x -= Lowbit(x);
        }
        return ret;
    }

    public void UpdateRange(int l, int r, int v) {
        Update(l, v);
        Update(r + 1, v);
    }
}

class Solution {
    public IList<bool> PalindromePath(int n, int[][] edges, string s,
                                      string[] queries) {
        var g = new List<int>[n];
        for (int i = 0; i < n; i++) g[i] = new List<int>();
        foreach (var e in edges) {
            g[e[0]].Add(e[1]);
            g[e[1]].Add(e[0]);
        }

        int LOG = 32 - System.Numerics.BitOperations.LeadingZeroCount((uint)n);
        int[,] fa = new int[n, LOG];
        int[] dep = new int[n], l = new int[n], r = new int[n];
        int timer = 0;

        Action<int, int> dfs = null;
        dfs = (u, p) => {
            l[u] = ++timer;
            fa[u, 0] = p;
            foreach (int v in g[u]) {
                if (v == p) {
                    continue;
                }
                dep[v] = dep[u] + 1;
                dfs(v, u);
            }
            r[u] = timer;
        };
        dfs(0, 0);

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                fa[i, j] = fa[fa[i, j - 1], j - 1];
            }
        }

        var bit = new BIT(n + 1);
        var chars = s.ToCharArray();
        for (int i = 0; i < n; i++) {
            bit.UpdateRange(l[i], r[i], 1 << (chars[i] - 'a'));
        }

        var ans = new List<bool>();
        foreach (var q in queries) {
            var parts = q.Split(' ');
            if (parts[0] == "update") {
                int u = int.Parse(parts[1]);
                char c = parts[2][0];
                bit.UpdateRange(l[u], r[u],
                                (1 << (chars[u] - 'a')) ^ (1 << (c - 'a')));
                chars[u] = c;
            } else {
                int u = int.Parse(parts[1]);
                int v = int.Parse(parts[2]);
                int w = Lca(u, v, dep, fa, LOG);
                int mask =
                    bit.Query(l[u]) ^ bit.Query(l[v]) ^ (1 << (chars[w] - 'a'));
                ans.Add(System.Numerics.BitOperations.PopCount((uint)mask) <=
                        1);
            }
        }
        return ans;
    }

    private int Lca(int u, int v, int[] dep, int[,] fa, int LOG) {
        if (dep[u] < dep[v]) {
            int t = u;
            u = v;
            v = t;
        }
        int diff = dep[u] - dep[v];
        for (int i = 0; i < LOG; i++) {
            if (((diff >> i) & 1) == 1) {
                u = fa[u, i];
            }
        }
        if (u == v) {
            return u;
        }
        for (int i = LOG - 1; i >= 0; i--) {
            if (fa[u, i] != fa[v, i]) {
                u = fa[u, i];
                v = fa[v, i];
            }
        }
        return fa[u, 0];
    }
}