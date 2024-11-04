impl Solution {
    pub fn compressed_string(word: String) -> String {
        // Handle empty string case
        if word.is_empty() {
            return String::new();
        }
        
        let mut comp = String::with_capacity(word.len() * 2);
        let chars: Vec<char> = word.chars().collect();
        
        let mut cnt = 1;
        let mut ch = chars[0];
        
        for i in 1..chars.len() {
            if chars[i] == ch && cnt < 9 {
                cnt += 1;
            } else {
                comp.push((cnt as u8 + b'0') as char);
                comp.push(ch);
                ch = chars[i];
                cnt = 1;
            }
        }
        
        // Handle the last group
        comp.push((cnt as u8 + b'0') as char);
        comp.push(ch);
        
        comp
    }
}