struct SegmentTree {
    k: usize,
    tree: Vec<Vec<i32>>,
}

impl SegmentTree {
    fn new(nums: &[i32], k: usize) -> Self {
        let n = nums.len();
        let size = 2 << (n as f64).log2().ceil() as usize;
        let mut tree = vec![vec![0; k + 1]; size];
        let mut seg = SegmentTree { k, tree };
        seg.build(nums, 1, 0, n - 1);
        seg
    }

    fn make_leaf(&mut self, o: usize, value: i32) {
        let mut info = vec![0; self.k + 1];
        let r = (value % self.k as i32) as usize;
        info[r] = 1;
        info[self.k] = r as i32;
        self.tree[o] = info;
    }

    fn merge_pre(&self, left: &[i32], right: &[i32]) -> Vec<i32> {
        let mut pre = vec![0; self.k + 1];
        let mul_l = left[self.k];
        let mul_r = right[self.k];
        pre[self.k] = (mul_l * mul_r) % self.k as i32;

        for x in 0..self.k {
            pre[x] = left[x];
        }
        for x in 0..self.k {
            pre[((mul_l * x as i32) % self.k as i32) as usize] += right[x];
        }
        pre
    }

    fn maintain(&mut self, o: usize) {
        let left = self.tree[o * 2].clone();
        let right = self.tree[o * 2 + 1].clone();
        self.tree[o] = self.merge_pre(&left, &right);
    }

    fn build(&mut self, nums: &[i32], o: usize, l: usize, r: usize) {
        if l == r {
            self.make_leaf(o, nums[l]);
            return;
        }
        let m = (l + r) / 2;
        self.build(nums, o * 2, l, m);
        self.build(nums, o * 2 + 1, m + 1, r);
        self.maintain(o);
    }

    pub fn update(&mut self, o: usize, l: usize, r: usize, index: usize, value: i32) {
        if l == r {
            self.make_leaf(o, value);
            return;
        }
        let m = (l + r) / 2;
        if index <= m {
            self.update(o * 2, l, m, index, value);
        } else {
            self.update(o * 2 + 1, m + 1, r, index, value);
        }
        self.maintain(o);
    }

    pub fn query(&self, o: usize, l: usize, r: usize, L: usize, R: usize) -> Vec<i32> {
        if L <= l && r <= R {
            return self.tree[o].clone();
        }
        let m = (l + r) / 2;
        if R <= m {
            return self.query(o * 2, l, m, L, R);
        }
        if L > m {
            return self.query(o * 2 + 1, m + 1, r, L, R);
        }
        let left = self.query(o * 2, l, m, L, R);
        let right = self.query(o * 2 + 1, m + 1, r, L, R);
        self.merge_pre(&left, &right)
    }
}

impl Solution {
    pub fn result_array(nums: Vec<i32>, k: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = nums.len();
        let k_usize = k as usize;
        let mut seg = SegmentTree::new(&nums, k_usize);
        let mut ans = Vec::new();

        for q in queries {
            let index = q[0] as usize;
            let value = q[1];
            let start = q[2] as usize;
            let x = q[3] as usize;
            seg.update(1, 0, n - 1, index, value);
            let pre = seg.query(1, 0, n - 1, start, n - 1);
            ans.push(pre[x]);
        }
        ans
    }
}