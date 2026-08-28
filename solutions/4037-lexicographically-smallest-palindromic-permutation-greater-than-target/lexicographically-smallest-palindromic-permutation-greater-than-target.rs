impl Solution {
    pub fn lex_palindromic_permutation(s: String, target: String) -> String {
        let n = s.len();
        // Special case: length of 1
        if n == 1 {
            return if s > target { s } else { String::new() };
        }
        
        // Count the frequency of each character
        let mut cnt = vec![0; 26];
        for c in s.chars() {
            cnt[(c as u8 - b'a') as usize] += 1;
        }
        
        // Check if it can form a palindrome and record the characters with odd occurrences
        let mut odd_char = String::new();
        for i in 0..26 {
            if cnt[i] % 2 == 1 {
                // More than one character appears an odd number of times, cannot form a palindrome
                if !odd_char.is_empty() {
                    return String::new();
                }
                odd_char = ((b'a' + i as u8) as char).to_string();
            }
            cnt[i] /= 2;  // It takes only half the characters to construct the left half
        }
        
        let mut prefix = String::new();
        
        // Construct the left part of each digit greedily
        for i in 0..n / 2 {
            let mut found = false;
            // Try to place the smallest character in lexicographical order
            for j in 0..26 {
                if cnt[j] == 0 {
                    continue;
                }
                
                cnt[j] -= 1;
                
                // check function
                let mut left = prefix.clone();
                left.push((b'a' + j as u8) as char);
                for k in (0..26).rev() {
                    for _ in 0..cnt[k] {
                        left.push((b'a' + k as u8) as char);
                    }
                }
                
                let mut palindrome = left.clone();
                palindrome.push_str(&odd_char);
                let reversed_left: String = left.chars().rev().collect();
                palindrome.push_str(&reversed_left);
                
                if palindrome > target {
                    // If the constructed palindrome is greater than target, choose the character
                    prefix.push((b'a' + j as u8) as char);
                    found = true;
                    break;
                } else {
                    cnt[j] += 1;  // Not meeting the conditions, reset the counter
                }
            }
            if !found {
                return String::new();  // Cannot construct a palindrome larger than target
            }
            
            if prefix.as_bytes()[i] > target.as_bytes()[i] {  // prefix is already greater than target
                let mut left = prefix.clone();
                for j in 0..26 {
                    for _ in 0..cnt[j] {
                        left.push((b'a' + j as u8) as char);
                    }
                }
                let mut palindrome = left.clone();
                palindrome.push_str(&odd_char);
                let reversed_left: String = left.chars().rev().collect();
                palindrome.push_str(&reversed_left);
                return palindrome;
            }
        }
        
        // Construct the final palindrome string
        let mut ans = prefix.clone();
        ans.push_str(&odd_char);
        let reversed_prefix: String = prefix.chars().rev().collect();
        ans.push_str(&reversed_prefix);
        ans
    }
}