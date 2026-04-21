struct UnionFind {
    fa: Vec<usize>,
    rank: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        UnionFind {
            fa: (0..n).collect(),
            rank: vec![0; n],
        }
    }
    
    fn find(&mut self, x: usize) -> usize {
        if self.fa[x] != x {
            self.fa[x] = self.find(self.fa[x]);
        }
        self.fa[x]
    }
    
    fn union(&mut self, x: usize, y: usize) {
        let mut x = self.find(x);
        let mut y = self.find(y);
        if x == y {
            return;
        }
        if self.rank[x] < self.rank[y] {
            std::mem::swap(&mut x, &mut y);
        }
        self.fa[y] = x;
        if self.rank[x] == self.rank[y] {
            self.rank[x] += 1;
        }
    }
}

use std::collections::HashMap;

impl Solution {
    pub fn minimum_hamming_distance(source: Vec<i32>, target: Vec<i32>, allowed_swaps: Vec<Vec<i32>>) -> i32 {
        let n = source.len();
        let mut uf = UnionFind::new(n);
        
        for swap in &allowed_swaps {
            uf.union(swap[0] as usize, swap[1] as usize);
        }
        
        let mut sets: HashMap<usize, HashMap<i32, i32>> = HashMap::new();
        for i in 0..n {
            let f = uf.find(i);
            *sets.entry(f).or_insert_with(HashMap::new)
                .entry(source[i]).or_insert(0) += 1;
        }
        
        let mut ans = 0;
        for i in 0..n {
            let f = uf.find(i);
            let cnt = sets.get_mut(&f).unwrap();
            if let Some(v) = cnt.get_mut(&target[i]) {
                if *v > 0 {
                    *v -= 1;
                    continue;
                }
            }
            ans += 1;
        }
        ans
    }
}