use std::collections::HashMap;

const MX: usize = 1_000_001;

lazy_static::lazy_static! {
    static ref FACTORS: Vec<Vec<i32>> = {
        let mut f = vec![vec![]; MX];
        for i in 2..MX {
            if f[i].is_empty() {
                for j in (i..MX).step_by(i) {
                    f[j].push(i as i32);
                }
            }
        }
        f
    };
}

impl Solution {
    pub fn min_jumps(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut edges: HashMap<i32, Vec<usize>> = HashMap::new();
        for (i, &a) in nums.iter().enumerate() {
            if FACTORS[a as usize].len() == 1 {
                edges.entry(a).or_default().push(i);
            }
        }
        let mut res = 0;
        let mut seen = vec![false; n];
        seen[n - 1] = true;
        let mut q = vec![n - 1];
        loop {
            let mut q2 = vec![];
            for &i in &q {
                if i == 0 { return res; }
                if i > 0 && !seen[i - 1] {
                    seen[i - 1] = true;
                    q2.push(i - 1);
                }
                if i < n - 1 && !seen[i + 1] {
                    seen[i + 1] = true;
                    q2.push(i + 1);
                }
                for &p in &FACTORS[nums[i] as usize] {
                    if let Some(list) = edges.get_mut(&p) {
                        for &j in list.iter() {
                            if !seen[j] {
                                seen[j] = true;
                                q2.push(j);
                            }
                        }
                        list.clear();
                    }
                }
            }
            q = q2;
            res += 1;
        }
    }
}