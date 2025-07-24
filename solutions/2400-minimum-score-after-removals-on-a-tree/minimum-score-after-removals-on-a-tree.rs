use std::cmp::{max, min};
use std::collections::VecDeque;

impl Solution {
    fn calc(a: i32, b: i32, c: i32) -> i32 {
        max(a, max(b, c)) - min(a, min(b, c))
    }

    pub fn minimum_score(nums: Vec<i32>, edges: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let mut e = vec![vec![]; n];
        for v in edges.iter() {
            e[v[0] as usize].push(v[1] as usize);
            e[v[1] as usize].push(v[0] as usize);
        }

        let mut total = 0;
        for &x in nums.iter() {
            total ^= x;
        }

        let mut res = i32::MAX;

        fn dfs2(
            x: usize,
            f: usize,
            oth: i32,
            anc: usize,
            nums: &Vec<i32>,
            e: &Vec<Vec<usize>>,
            res: &mut i32,
            total: i32,
        ) -> i32 {
            let mut son = nums[x];
            for &y in &e[x] {
                if y == f {
                    continue;
                }
                son ^= dfs2(y, x, oth, anc, nums, e, res, total);
            }
            if f == anc {
                return son;
            }
            *res = min(*res, Solution::calc(oth, son, total ^ oth ^ son));
            son
        }

        fn dfs(
            x: usize,
            f: usize,
            nums: &Vec<i32>,
            e: &Vec<Vec<usize>>,
            res: &mut i32,
            total: i32,
        ) -> i32 {
            let mut son = nums[x];
            for &y in &e[x] {
                if y == f {
                    continue;
                }
                son ^= dfs(y, x, nums, e, res, total);
            }
            for &y in &e[x] {
                if y == f {
                    dfs2(y, x, son, x, nums, e, res, total);
                }
            }
            son
        }

        dfs(0, usize::MAX, &nums, &e, &mut res, total);
        res
    }
}