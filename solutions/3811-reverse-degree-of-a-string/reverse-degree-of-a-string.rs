impl Solution {
    pub fn reverse_degree(s: String) -> i32 {
        let mut ans = 0;
        for (i, ch) in s.chars().enumerate() {
            let index = (i + 1) as i32;
            ans += (26 - (ch as i32 - 'a' as i32)) * index;
        }
        ans
    }
}