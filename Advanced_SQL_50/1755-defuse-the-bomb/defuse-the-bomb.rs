impl Solution {
    pub fn decrypt(code: Vec<i32>, k: i32) -> Vec<i32> {
        let n = code.len();
        let mut res = vec![0; n];
        
        if k == 0 { return res; }
        
        let mut l = 0;
        let mut cur_sum = 0;
        for r in 0..(n + k.abs() as usize) {
            cur_sum += code[r % n];
            
            if r - l + 1 > k.abs() as usize {
                cur_sum -= code[l % n];
                l = (l + 1) % n;
            }
            
            if r - l + 1 == k.abs() as usize {
                if k > 0 {
                    res[((l as i32 - 1 + n as i32) as usize) % n] = cur_sum;
                } else {
                    res[(r + 1) % n] = cur_sum;
                }
            }
        }
        res
    }
}