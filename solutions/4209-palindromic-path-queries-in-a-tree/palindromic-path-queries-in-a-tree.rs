struct BIT {
    n: usize,
    tree: Vec<i32>,
}

impl BIT {
    fn new(n: usize) -> Self {
        BIT {
            n,
            tree: vec![0; n + 1],
        }
    }

    fn lowbit(x: usize) -> usize {
        x & x.wrapping_neg()
    }

    fn update(&mut self, mut x: usize, v: i32) {
        while x <= self.n {
            self.tree[x] ^= v;
            x += Self::lowbit(x);
        }
    }

    fn query(&self, mut x: usize) -> i32 {
        let mut ret = 0;
        while x > 0 {
            ret ^= self.tree[x];
            x -= Self::lowbit(x);
        }
        ret
    }

    fn update_range(&mut self, l: usize, r: usize, v: i32) {
        self.update(l, v);
        self.update(r + 1, v);
    }
}

fn dfs(
    u: usize,
    p: usize,
    g: &mut Vec<Vec<usize>>,
    fa: &mut Vec<Vec<usize>>,
    dep: &mut Vec<usize>,
    l: &mut Vec<usize>,
    r: &mut Vec<usize>,
    timer: &mut usize,
) {
    *timer += 1;
    l[u] = *timer;
    fa[u][0] = p;

    let neighbors = std::mem::take(&mut g[u]);
    for &v in &neighbors {
        if v == p {
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u, g, fa, dep, l, r, timer);
    }
    g[u] = neighbors;

    r[u] = *timer;
}

fn build_fa(fa: &mut Vec<Vec<usize>>, log: usize, n: usize) {
    for j in 1..log {
        for i in 0..n {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }
}

fn lca(
    mut u: usize,
    mut v: usize,
    fa: &Vec<Vec<usize>>,
    dep: &Vec<usize>,
    log: usize,
) -> usize {
    if dep[u] < dep[v] {
        std::mem::swap(&mut u, &mut v);
    }
    let diff = dep[u] - dep[v];
    for i in 0..log {
        if (diff >> i) & 1 == 1 {
            u = fa[u][i];
        }
    }
    if u == v {
        return u;
    }
    for i in (0..log).rev() {
        if fa[u][i] != fa[v][i] {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    fa[u][0]
}

impl Solution {
    pub fn palindrome_path(
        n: i32,
        edges: Vec<Vec<i32>>,
        s: String,
        queries: Vec<String>,
    ) -> Vec<bool> {
        let n = n as usize;

        let mut g: Vec<Vec<usize>> = vec![vec![]; n];
        for e in &edges {
            let u = e[0] as usize;
            let v = e[1] as usize;
            g[u].push(v);
            g[v].push(u);
        }

        let log = (32 - (n as u32).leading_zeros()) as usize;
        let mut fa: Vec<Vec<usize>> = vec![vec![0usize; log]; n];
        let mut dep: Vec<usize> = vec![0usize; n];
        let mut l: Vec<usize> = vec![0usize; n];
        let mut r: Vec<usize> = vec![0usize; n];
        let mut timer: usize = 0;

        dfs(0, 0, &mut g, &mut fa, &mut dep, &mut l, &mut r, &mut timer);
        build_fa(&mut fa, log, n);

        let mut bit = BIT::new(n + 1);
        let mut chars: Vec<u8> = s.bytes().collect();
        for i in 0..n {
            let mask = 1i32 << (chars[i] - b'a');
            bit.update_range(l[i], r[i], mask);
        }

        let mut ans: Vec<bool> = Vec::new();
        for q in &queries {
            let parts: Vec<&str> = q.split_whitespace().collect();
            if parts[0] == "update" {
                let u: usize = parts[1].parse().unwrap();
                let c = parts[2].as_bytes()[0];
                let old = 1i32 << (chars[u] - b'a');
                let new = 1i32 << (c - b'a');
                bit.update_range(l[u], r[u], old ^ new);
                chars[u] = c;
            } else {
                let u: usize = parts[1].parse().unwrap();
                let v: usize = parts[2].parse().unwrap();
                let w = lca(u, v, &fa, &dep, log);
                let mask = bit.query(l[u])
                    ^ bit.query(l[v])
                    ^ (1i32 << (chars[w] - b'a'));
                ans.push((mask as u32).count_ones() <= 1);
            }
        }

        ans
    }
}