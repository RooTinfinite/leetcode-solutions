impl Solution {
    pub fn can_make_subsequence(source: String, target: String) -> bool {
        let src_bytes = source.as_bytes();
        let tgt_bytes = target.as_bytes();
        let (src_len, tgt_len) = (src_bytes.len(), tgt_bytes.len());
        
        let mut target_byte = tgt_bytes[0];
        let mut tgt_idx = 0;
        
        for &src_byte in src_bytes {
            let next_byte = if src_byte == b'z' { b'a' } else { src_byte + 1 };
            
            if src_byte == target_byte || next_byte == target_byte {
                tgt_idx += 1;
                if tgt_idx == tgt_len {
                    break;
                }
                target_byte = tgt_bytes[tgt_idx];
            }
        }
        
        tgt_idx == tgt_len
    }
}