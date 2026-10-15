use std::collections::HashMap;

struct BIT {
    size: usize,
    _tree1: Vec<i64>,
    _tree2: Vec<i64>,
}

impl BIT {
    fn new(n: usize) -> Self {
        BIT {
            size: n,
            _tree1: vec![0; n + 2],
            _tree2: vec![0; n + 2],
        }
    }

    fn _lowbit(index: usize) -> usize {
        index & index.wrapping_neg()
    }

    fn add(&mut self, left: usize, right: usize, delta: i64) {
        self._add(left, delta);
        self._add(right + 1, -delta);
    }

    fn query(&self, left: usize, right: usize) -> i64 {
        let left_val = if left == 0 { 0 } else { self._query(left - 1) };
        self._query(right) - left_val
    }

    fn _add(&mut self, mut index: usize, delta: i64) {
        index += 1;
        let raw_index = index as i64;
        while index <= self.size {
            self._tree1[index] += delta;
            self._tree2[index] += raw_index * delta;
            index += Self::_lowbit(index);
        }
    }

    fn _query(&self, mut index: usize) -> i64 {
        index += 1;
        let raw_index = (index + 1) as i64;
        if index > self.size {
            index = self.size;
        }
        let mut res: i64 = 0;
        while index > 0 {
            res += raw_index * self._tree1[index] - self._tree2[index];
            index -= Self::_lowbit(index);
        }
        res
    }
}

impl Solution {
    pub fn sum_counts(A: Vec<i32>) -> i32 {
        let n = A.len();
        let mut res: i64 = 0;
        let mut cur: i64 = 0;
        let mut bit = BIT::new(n + 10);
        let mut seen: HashMap<i32, i32> = HashMap::new();
        let r#mod: i64 = 1_000_000_007;

        for (i, &a) in A.iter().enumerate() {
            let j = seen.get(&a).unwrap_or(&-1) + 1;
            let q = bit.query(j as usize, i);
            cur = (cur + q * 2 + (i as i64) - (j as i64) + 1) % r#mod;
            res = (res + cur) % r#mod;
            bit.add(j as usize, i, 1);
            seen.insert(a, i as i32);
        }

        res as i32
    }
}