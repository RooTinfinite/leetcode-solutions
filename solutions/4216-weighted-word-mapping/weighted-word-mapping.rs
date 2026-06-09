impl Solution {
    pub fn map_word_weights(words: Vec<String>, weights: Vec<i32>) -> String {
        let mut ans = String::with_capacity(words.len());

        for word in words {
            let mut s = 0;
            for c in word.bytes() {
                s += weights[(c - b'a') as usize];
            }
            ans.push((b'z' - (s % 26) as u8) as char);
        }

        ans
    }
}