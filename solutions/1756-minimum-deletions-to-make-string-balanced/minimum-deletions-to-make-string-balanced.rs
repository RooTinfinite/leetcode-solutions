impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let mut b_count = 0;
        let mut res = 0;
        
        for &b in s.as_bytes() {
            if b == b'b' {
                b_count += 1;
            } else {
                let delete_current_a = res + 1;
                if delete_current_a < b_count {
                    res = delete_current_a;
                } else {
                    res = b_count;
                }
            }
        }
        
        res
    }
}