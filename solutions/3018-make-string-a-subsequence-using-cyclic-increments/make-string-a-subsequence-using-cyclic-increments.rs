impl Solution {
    pub fn can_make_subsequence(source: String, target: String) -> bool {
        let mut target_idx = 0;
        let target_len = target.len();
        let target_bytes = target.as_bytes();
        
        for curr_char in source.bytes() {
            if target_idx < target_len && 
               (target_bytes[target_idx] as i32 - curr_char as i32 + 26) % 26 <= 1 {
                target_idx += 1;
            }
        }
        target_idx == target_len
    }
}