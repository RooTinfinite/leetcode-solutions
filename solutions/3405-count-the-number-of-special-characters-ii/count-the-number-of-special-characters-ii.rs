impl Solution {
    pub fn number_of_special_chars(word: String) -> i32 {
        let mut last_low = [-1i32; 26];
        let mut first_up = [-1i32; 26];
        for (i, c) in word.chars().enumerate() {
            if c.is_ascii_lowercase() {
                last_low[(c as u8 - b'a') as usize] = i as i32;
            } else {
                let idx = (c as u8 - b'A') as usize;
                if first_up[idx] == -1 {
                    first_up[idx] = i as i32;
                }
            }
        }
        let mut ans = 0;
        for i in 0..26 {
            if last_low[i] != -1 && first_up[i] != -1 && last_low[i] < first_up[i] {
                ans += 1;
            }
        }
        ans
    }
}