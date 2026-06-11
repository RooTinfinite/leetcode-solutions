var assignEdgeWeights = function (edges) {
    const MOD = 1000000007n;

    const qpow = (x, y) => {
        let res = 1n;
        let base = BigInt(x);
        let exp = y;
        while (exp > 0) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return Number(res);
    };

    const dfs = (g, x, f) => {
        let maxDep = 0;
        for (const y of g[x]) {
            if (y === f) continue;
            maxDep = Math.max(maxDep, dfs(g, y, x) + 1);
        }
        return maxDep;
    };

    const n = edges.length + 1;
    const g = Array.from({ length: n + 1 }, () => []);

    for (let i = 0; i < edges.length; i++) {
        const u = edges[i][0];
        const v = edges[i][1];
        g[u].push(v);
        g[v].push(u);
    }

    const maxDep = dfs(g, 1, 0);
    return qpow(2, maxDep - 1);
};