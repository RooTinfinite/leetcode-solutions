impl Solution {
    pub fn max_sum_of_squares(num: i32, sum: i32) -> String {
        if sum > 9 * num {
            return String::new();
        }
        let q = sum / 9;
        let r = sum % 9;
        let mut ans = "9".repeat(q as usize);
        if r > 0 {
            ans.push((b'0' + r as u8) as char);
        }
        ans.push_str(&"0".repeat(num as usize - ans.len()));
        ans
    }
}