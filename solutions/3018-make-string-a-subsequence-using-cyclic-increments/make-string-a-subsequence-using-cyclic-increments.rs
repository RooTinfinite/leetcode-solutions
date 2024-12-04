impl Solution {
    pub fn can_make_subsequence(source: String, target: String) -> bool {
        let src_bytes = source.as_bytes();
        let tgt_bytes = target.as_bytes();
        let (src_len, tgt_len) = (src_bytes.len(), tgt_bytes.len());
        let mut target_char = tgt_bytes[0];
        
        let (mut src_idx, mut tgt_idx) = (0, 0);
        while src_idx < src_len && tgt_idx < tgt_len {
            let src_char = src_bytes[src_idx];
            
            if src_char == target_char || 
               src_char + 1 == target_char ||
               (src_char == b'z' && target_char == b'a') {
                tgt_idx += 1;
                if tgt_idx < tgt_len {
                    target_char = tgt_bytes[tgt_idx];
                }
            }
            
            src_idx += 1;
        }
        
        tgt_idx == tgt_len
    }
}