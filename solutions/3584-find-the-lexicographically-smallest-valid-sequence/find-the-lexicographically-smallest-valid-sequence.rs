impl Solution {
    pub fn valid_sequence(word1: String, word2: String) -> Vec<i32> {
        let n = word1.len();
        let m = word2.len();
        let w1 = word1.as_bytes();
        let w2 = word2.as_bytes();
        let mut last = vec![-1; m];
        let mut j = m as i32 - 1;
        for i in (0..n).rev() {
            if j >= 0 && w1[i] == w2[j as usize] {
                last[j as usize] = i as i32;
                j -= 1;
            }
        }
        let mut res = Vec::new();
        let mut skip = 0;
        let mut j = 0;
        for i in 0..n {
            if j == m { break; }
            if w1[i] == w2[j] || (skip == 0 && (j == m - 1 || (i as i32) < last[j + 1])) {
                if w1[i] != w2[j] {
                    skip += 1;
                }
                res.push(i as i32);
                j += 1;
            }
        }
        if j == m { res } else { vec![] }
    }
}