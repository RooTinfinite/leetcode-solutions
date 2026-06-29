impl Solution {
    pub fn num_of_strings(patterns: Vec<String>, word: String) -> i32 {
        let mut res = 0;
        for pattern in patterns {
            if Self::check(&pattern, &word) {
                res += 1;
            }
        }
        res
    }
    
    fn check(pattern: &str, word: &str) -> bool {
        let m = pattern.len();
        let n = word.len();
        
        let pattern_bytes = pattern.as_bytes();
        let word_bytes = word.as_bytes();
        
        // generate the prefix array of the pattern
        let mut pi = vec![0; m];
        let mut j = 0;
        for i in 1..m {
            while j > 0 && pattern_bytes[i] != pattern_bytes[j] {
                j = pi[j - 1];
            }
            if pattern_bytes[i] == pattern_bytes[j] {
                j += 1;
            }
            pi[i] = j;
        }
        
        // using prefix arrays for matching
        j = 0;
        for i in 0..n {
            while j > 0 && word_bytes[i] != pattern_bytes[j] {
                j = pi[j - 1];
            }
            if word_bytes[i] == pattern_bytes[j] {
                j += 1;
            }
            if j == m {
                return true;
            }
        }
        false
    }
}