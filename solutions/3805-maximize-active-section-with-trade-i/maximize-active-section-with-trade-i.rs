impl Solution {
    pub fn max_active_sections_after_trade(s: String) -> i32 {
        let n = s.len();
        let cnt1 = s.chars().filter(|&c| c == '1').count() as i32;

        let mut i = 0;
        let mut best_gain = 0;
        let mut prev = i32::MIN;
        let mut cur = 0;
        let bytes = s.as_bytes();

        while i < n {
            let start = i;
            while i < n && bytes[i] == bytes[start] {
                i += 1;
            }
            if bytes[start] == b'0' {
                cur = (i - start) as i32;
                if prev != i32::MIN {
                    best_gain = best_gain.max(prev + cur);
                }
                prev = cur;
            }
        }

        cnt1 + best_gain
    }
}