impl Solution {
    pub fn can_make_subsequence(source: String, target: String) -> bool {
        let src_bytes = source.as_bytes();
        let tgt_bytes = target.as_bytes();
        let (mut src_idx, mut tgt_idx) = (0, 0);
        
        while src_idx < src_bytes.len() && tgt_idx < tgt_bytes.len() {
            if src_bytes[src_idx] == tgt_bytes[tgt_idx] || 
               (src_bytes[src_idx] == b'z' && tgt_bytes[tgt_idx] == b'a') || 
               (src_bytes[src_idx] + 1 == tgt_bytes[tgt_idx]) {
                src_idx += 1;
                tgt_idx += 1;
            } else {
                src_idx += 1;
            }
        }
        tgt_idx == tgt_bytes.len()
    }
}