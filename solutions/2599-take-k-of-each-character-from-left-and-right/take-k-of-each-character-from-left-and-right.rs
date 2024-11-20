impl Solution {
    pub fn take_characters(s: String, k: i32) -> i32 {
        // Total counts
        let mut count = vec![0; 3];
        for c in s.chars() {
            count[(c as u8 - b'a') as usize] += 1;
        }
        
        if count.iter().min().unwrap() < &k {
            return -1;
        }
        
        // Sliding Window
        let s_bytes = s.as_bytes();
        let mut res = i32::MAX;
        let mut l = 0;
        for r in 0..s_bytes.len() {
            count[(s_bytes[r] - b'a') as usize] -= 1;
            
            while count.iter().min().unwrap() < &k {
                count[(s_bytes[l] - b'a') as usize] += 1;
                l += 1;
            }
            res = res.min(s_bytes.len() as i32 - (r as i32 - l as i32 + 1));
        }
        res
    }
}
