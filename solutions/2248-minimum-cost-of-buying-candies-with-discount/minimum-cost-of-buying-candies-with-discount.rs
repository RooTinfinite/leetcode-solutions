impl Solution {
    pub fn minimum_cost(mut cost: Vec<i32>) -> i32 {
        cost.sort_by(|a, b| b.cmp(a));
        let mut res = 0;
        let n = cost.len();
        for i in 0..n {
            if i % 3 != 2 {
                res += cost[i];
            }
        }
        res
    }
}