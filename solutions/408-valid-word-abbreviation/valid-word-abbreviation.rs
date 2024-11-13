impl Solution {
    fn parse_number(abbreviation: &str, start_pos: usize) -> u32 {
        let mut number = 0;
        let chars: Vec<char> = abbreviation.chars().collect();
        let mut pos = start_pos;
        while pos < chars.len() && chars[pos].is_digit(10) {
            number = number * 10 + chars[pos].to_digit(10).unwrap();
            pos += 1;
        }
        number
    }
    
    pub fn valid_word_abbreviation(word: String, abbreviation: String) -> bool {
        let word_chars: Vec<char> = word.chars().collect();
        let abbr_chars: Vec<char> = abbreviation.chars().collect();
        let mut word_pos = 0;
        let mut abbr_pos = 0;
        
        while abbr_pos < abbr_chars.len() && word_pos < word_chars.len() {
            if abbr_chars[abbr_pos].is_alphabetic() {
                if abbr_chars[abbr_pos] != word_chars[word_pos] {
                    return false;
                }
                word_pos += 1;
                abbr_pos += 1;
            } else {
                if abbr_chars[abbr_pos] == '0' {
                    return false;
                }
                
                let skip_count = Self::parse_number(&abbreviation, abbr_pos) as usize;
                abbr_pos += skip_count.to_string().len();
                word_pos += skip_count;
            }
        }
        
        abbr_pos == abbr_chars.len() && word_pos == word_chars.len()
    }
}