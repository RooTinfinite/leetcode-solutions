impl Solution {
    pub fn make_fancy_string(s: String) -> String {
        let mut chars: Vec<char> = s.chars().collect();
        
        // Return original string if length is less than 3
        if chars.len() < 3 {
            return s;
        }
        
        // j keeps track of the position where we'll place
        // the next valid character
        let mut j = 2;
        
        // Iterate through string starting from index 2
        for i in 2..chars.len() {
            // Add current character if it's different from
            // either of the two previous characters
            if chars[i] != chars[j - 1] || chars[i] != chars[j - 2] {
                chars[j] = chars[i];
                j += 1;
            }
        }
        
        // Truncate vector to remove excess characters
        chars.truncate(j);
        
        // Convert back to String
        chars.into_iter().collect()
    }
}