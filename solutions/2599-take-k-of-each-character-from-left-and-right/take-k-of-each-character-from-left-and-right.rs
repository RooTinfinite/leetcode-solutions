impl Solution {
    pub fn take_characters(s: String, k: i32) -> i32 {
        let mut freq = vec![0; 3];
        let n = s.len();
        let s_bytes = s.as_bytes();
        
        for &c in s_bytes {
            freq[(c - b'a') as usize] += 1;
        }
        
        if freq[0] < k || freq[1] < k || freq[2] < k {
            return -1;
        }
        
        let mut curr = vec![0; 3];
        let mut max_len = 0;
        let mut left = 0;
        
        for right in 0..n {
            curr[(s_bytes[right] - b'a') as usize] += 1;
            
            while left <= right && (curr[0] > freq[0] - k ||
                   curr[1] > freq[1] - k ||
                   curr[2] > freq[2] - k) {
                curr[(s_bytes[left] - b'a') as usize] -= 1;
                left += 1;
            }
            
            max_len = max_len.max(right - left + 1);
        }
        
        (n - max_len) as i32
    }
}