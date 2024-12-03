impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let mut i = 0;
        let mut j = 0;
        let mut res = Vec::new();
        let s_chars: Vec<char> = s.chars().collect();
        
        while i < s.len() && j < spaces.len() {
            if i < spaces[j] as usize {
                res.push(s_chars[i]);
                i += 1;
            } else {
                res.push(' ');
                j += 1;
            }
        }
        
        if i < s.len() {
            res.extend(&s_chars[i..]);
        }
        
        res.into_iter().collect()
    }
}