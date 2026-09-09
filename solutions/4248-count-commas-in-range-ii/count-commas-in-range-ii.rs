impl Solution {
    pub fn count_commas(n: i64) -> i64 {
        let mut p: i64 = 1000;
        let mut res: i64 = 0;
        while p <= n {
            res += n - p + 1;
            p *= 1000;
        }
        res
    }
}