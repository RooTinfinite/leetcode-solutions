use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn remove_invalid_parentheses(s: String) -> Vec<String> {
        let is_valid = |string: &str| -> bool {
            let mut count = 0;
            for c in string.chars() {
                if c == '(' { count += 1; }
                else if c == ')' {
                    if count == 0 { return false; }
                    count -= 1;
                }
            }
            count == 0
        };
        
        let mut result = Vec::new();
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();
        
        queue.push_back(s.clone());
        visited.insert(s);
        let mut found = false;
        
        while let Some(curr) = queue.pop_front() {
            if is_valid(&curr) {
                result.push(curr.clone());
                found = true;
            }
            
            if found { continue; }
            
            let chars: Vec<char> = curr.chars().collect();
            for i in 0..chars.len() {
                if chars[i] != '(' && chars[i] != ')' { continue; }
                let mut next_state = String::with_capacity(chars.len() - 1);
                for j in 0..chars.len() {
                    if i != j { next_state.push(chars[j]); }
                }
                
                if !visited.contains(&next_state) {
                    visited.insert(next_state.clone());
                    queue.push_back(next_state);
                }
            }
        }
        result
    }
}