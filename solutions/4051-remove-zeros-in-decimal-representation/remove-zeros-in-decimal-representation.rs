impl Solution {
    pub fn remove_zeros(n: i64) -> i64 {
        let result = n.to_string().replace("0", "");
        result.parse::<i64>().unwrap()
    }
}