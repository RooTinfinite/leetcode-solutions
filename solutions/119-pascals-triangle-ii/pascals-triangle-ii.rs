impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut res = vec![1];
        let mut prev: i64 = 1;  // use i64 for the calculations
        for k in 1..=row_index {
            let next_val = prev * (row_index - k + 1) as i64 / k as i64;
            res.push(next_val as i32);
            prev = next_val;
        }
        res
    }
}