impl Solution {
    pub fn is_circular_sentence(sentence: String) -> bool {
        let chars: Vec<char> = sentence.chars().collect();
        let n = chars.len();
        
        // Check first and last character
        if chars[0] != chars[n - 1] {
            return false;
        }
        
        // Check characters around spaces
        for i in 1..n-1 {
            if chars[i] == ' ' && chars[i-1] != chars[i+1] {
                return false;
            }
        }
        
        true
    }
}