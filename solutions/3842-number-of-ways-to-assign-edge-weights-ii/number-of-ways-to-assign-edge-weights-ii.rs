use std::collections::VecDeque;

const MOD: i64 = 1_000_000_007;
const N: usize = 100010;

lazy_static! {
    static ref P2: Vec<i64> = {
        let mut p2 = vec![0; N];
        p2[0] = 1;
        for i in 1..N {
            p2[i] = p2[i - 1] * 2 % MOD;
        }
        p2
    };
}

struct LCA {
    n: usize,
    m: usize,
    d: Vec<i32>,
    e: Vec<Vec<usize>>,
    f: Vec<Vec<usize>>,
}

impl LCA {
    fn new(edges: &Vec<Vec<i32>>, root: usize) -> Self {
        let n = edges.len() + 1;
        let m = (n as f64).log2() as usize + 2;
        
        let mut e = vec![vec![]; n + 1];
        for edge in edges {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            e[u].push(v);
            e[v].push(u);
        }
        
        let mut lca = LCA {
            n,
            m,
            d: vec![0; n + 1],
            e,
            f: vec![vec![0; m]; n + 1],
        };
        
        lca.dfs(root, 0);
        
        for i in 1..m {
            for x in 1..=n {
                lca.f[x][i] = lca.f[lca.f[x][i - 1]][i - 1];
            }
        }
        
        lca
    }
    
    fn dfs(&mut self, x: usize, fa: usize) {
        self.f[x][0] = fa;
        for i in 0..self.e[x].len() {
            let y = self.e[x][i];
            if y == fa {
                continue;
            }
            self.d[y] = self.d[x] + 1;
            self.dfs(y, x);
        }
    }
    
    fn lca(&self, mut x: usize, mut y: usize) -> usize {
        if self.d[x] > self.d[y] {
            std::mem::swap(&mut x, &mut y);
        }
        
        // raise y to the same depth as x
        let diff = self.d[y] - self.d[x];
        for i in (0..self.m).rev() {
            if diff & (1 << i) != 0 {
                y = self.f[y][i];
            }
        }
        
        if x == y {
            return x;
        }
        
        for i in (0..self.m).rev() {
            if self.f[x][i] != self.f[y][i] {
                x = self.f[x][i];
                y = self.f[y][i];
            }
        }
        
        self.f[x][0]
    }
    
    fn dis(&self, x: usize, y: usize) -> i32 {
        self.d[x] + self.d[y] - self.d[self.lca(x, y)] * 2
    }
}

impl Solution {
    fn assign_edge_weights(edges: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let lca = LCA::new(&edges, 1);
        let m = queries.len();
        let mut res = vec![0; m];
        
        for i in 0..m {
            let x = queries[i][0];
            let y = queries[i][1];
            if x != y {
                let dist = lca.dis(x as usize, y as usize) as usize;
                res[i] = P2[dist - 1] as i32;
            }
        }
        
        res
    }
}