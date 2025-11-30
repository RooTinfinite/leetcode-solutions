impl Solution {
    pub fn kth_character(k: i64, operations: Vec<i32>) -> char {
        let mut ans = 0;
        let mut k = k - 1;
        for i in (0..64 - k.leading_zeros()).rev() {
            if (k >> i) & 1 == 1 {
                ans += operations[i as usize];
            }
        }
        (b'a' + (ans % 26) as u8) as char
    }
}