impl Solution {
    pub fn decrypt(circ: Vec<i32>, k: i32) -> Vec<i32> {
        let n = circ.len();
        let mut result = vec![0; n];
        
        if k == 0 {
            return result;
        }
        
        let mut w_sum = 0;
        let start = if k > 0 { 1 } else { n as i32 + k } as usize;
        let end = if k > 0 { k } else { n as i32 - 1 } as usize;
        
        for i in start..=end {
            w_sum += circ[i % n];
        }
        
        for i in 0..n {
            result[i] = w_sum;
            w_sum -= circ[(start + i) % n];
            w_sum += circ[(end + i + 1) % n];
        }
        
        result
    }
}