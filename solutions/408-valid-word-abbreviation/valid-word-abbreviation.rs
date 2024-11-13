impl Solution {
    pub fn valid_word_abbreviation(word: String, abbr: String) -> bool {
        let word = word.as_bytes();
        let abbr = abbr.as_bytes();
        let mut i = 0;
        let mut j = 0;
       
        while i < word.len() && j < abbr.len() {
            if abbr[j].is_ascii_digit() {
                if abbr[j] == b'0' { return false; }
                let mut num = 0;
                while j < abbr.len() && abbr[j].is_ascii_digit() {
                    num = num * 10 + (abbr[j] - b'0') as usize;
                    j += 1;
                }
                i += num;
            } else {
                if word[i] != abbr[j] { return false; }
                i += 1;
                j += 1;
            }
        }
        i == word.len() && j == abbr.len()
    }
}