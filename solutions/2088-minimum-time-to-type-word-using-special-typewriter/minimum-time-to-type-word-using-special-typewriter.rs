impl Solution {
    pub fn min_time_to_type(word: String) -> i32 {
        let mut ans = word.len() as i32;
        let mut cur = 1i32;
        for b in word.bytes() {
            let pos = (b - b'a' + 1) as i32;
            let diff = (pos - cur).abs();
            ans += diff.min(26 - diff);
            cur = pos;
        }
        ans
    }
}