impl Solution {
    const MOD: i64 = 1_000_000_007;

    fn qpow(mut x: i64, mut y: i64) -> i64 {
        let mut res = 1;
        while y > 0 {
            if y & 1 == 1 {
                res = (res * x) % Self::MOD;
            }
            x = (x * x) % Self::MOD;
            y >>= 1;
        }
        res
    }

    fn dfs(g: &Vec<Vec<usize>>, x: usize, f: usize) -> i64 {
        let mut max_dep = 0;
        for &y in &g[x] {
            if y == f {
                continue;
            }
            max_dep = max_dep.max(Self::dfs(g, y, x) + 1);
        }
        max_dep
    }

    pub fn assign_edge_weights(edges: Vec<Vec<i32>>) -> i32 {
        let n = edges.len() + 1;
        let mut g = vec![vec![]; n + 1];
        for e in edges {
            let u = e[0] as usize;
            let v = e[1] as usize;
            g[u].push(v);
            g[v].push(u);
        }
        let max_dep = Self::dfs(&g, 1, 0);
        Self::qpow(2, max_dep - 1) as i32
    }
}