use std::collections::VecDeque;

impl Solution {
    pub fn longest_subsequence_repeated_k(s: String, k: i32) -> String {
        let mut freq = [0; 26];
        for ch in s.chars() {
            freq[(ch as u8 - b'a') as usize] += 1;
        }
        
        let mut candidate: Vec<char> = Vec::new();
        for i in (0..26).rev() {
            if freq[i] >= k {
                candidate.push((b'a' + i as u8) as char);
            }
        }
        
        let mut q = VecDeque::new();
        for &ch in &candidate {
            q.push_back(ch.to_string());
        }
        let mut ans = String::new();
        while let Some(curr) = q.pop_front() {
            if curr.len() > ans.len() {
                ans = curr.clone();
            }
            // generate the next candidate string
            for &ch in &candidate {
                let next = curr.clone() + &ch.to_string();
                if Self::is_k_repeated_subsequence(&s, &next, k) {
                    q.push_back(next);
                }
            }
        }
        
        ans
    }
    
    fn is_k_repeated_subsequence(s: &str, t: &str, k: i32) -> bool {
        let mut pos = 0;
        let mut matched = 0;
        let t_chars: Vec<char> = t.chars().collect();
        let m = t_chars.len();
        
        for ch in s.chars() {
            if ch == t_chars[pos] {
                pos += 1;
                if pos == m {
                    pos = 0;
                    matched += 1;
                    if matched == k {
                        return true;
                    }
                }
            }
        }
        false
    }
}