impl Solution {
    fn get_distance(p: i32, q: i32) -> i32 {
        let x1 = p / 6;
        let y1 = p % 6;
        let x2 = q / 6;
        let y2 = q % 6;
        (x1 - x2).abs() + (y1 - y2).abs()
    }

    pub fn minimum_distance(word: String) -> i32 {
        let n = word.len();
        let word_chars: Vec<char> = word.chars().collect();
        let mut dp = vec![vec![vec![i32::MAX >> 1; 26]; 26]; n];
        let first_char = (word_chars[0] as u8 - b'A') as usize;
        for i in 0..26 {
            dp[0][i][first_char] = 0;
            dp[0][first_char][i] = 0;
        }
        
        for i in 1..n {
            let cur = (word_chars[i] as u8 - b'A') as i32;
            let prev = (word_chars[i - 1] as u8 - b'A') as i32;
            let d = Self::get_distance(prev, cur);
            
            for j in 0..26 {
                let j_i32 = j as i32;
                dp[i][cur as usize][j] = dp[i][cur as usize][j].min(
                    dp[i - 1][prev as usize][j].saturating_add(d)
                );
                dp[i][j][cur as usize] = dp[i][j][cur as usize].min(
                    dp[i - 1][j][prev as usize].saturating_add(d)
                );
                
                if prev == j_i32 {
                    for k in 0..26 {
                        let d0 = Self::get_distance(k as i32, cur);
                        dp[i][cur as usize][j] = dp[i][cur as usize][j].min(
                            dp[i - 1][k][j].saturating_add(d0)
                        );
                        dp[i][j][cur as usize] = dp[i][j][cur as usize].min(
                            dp[i - 1][j][k].saturating_add(d0)
                        );
                    }
                }
            }
        }
        
        let mut ans = i32::MAX >> 1;
        for i in 0..26 {
            for j in 0..26 {
                ans = ans.min(dp[n - 1][i][j]);
            }
        }
        ans
    }
}