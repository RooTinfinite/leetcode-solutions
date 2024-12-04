impl Solution {
    pub fn can_make_subsequence(source: String, target: String) -> bool {
        let src_chars: Vec<char> = source.chars().collect();
        let tgt_chars: Vec<char> = target.chars().collect();
        let (src_len, tgt_len) = (src_chars.len(), tgt_chars.len());
        
        let mut target_char = tgt_chars[0];
        let mut tgt_idx = 0;
        
        for src_char in src_chars {
            if src_char == target_char || 
               ((src_char as u8 + 1) as char == target_char) ||
               (src_char == 'z' && target_char == 'a') {
                tgt_idx += 1;
                if tgt_idx == tgt_len {
                    break;
                }
                target_char = tgt_chars[tgt_idx];
            }
        }
        
        tgt_idx == tgt_len
    }
}