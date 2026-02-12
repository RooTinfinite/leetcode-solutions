impl Solution {
    pub fn longest_balanced(s: String) -> i32 {
        let n = s.len();
        let mut res = 0;
        let bytes = s.as_bytes();
        
        for i in 0..n {
            let mut cnt = [0; 26];
            for j in i..n {
                let c = (bytes[j] - b'a') as usize;
                cnt[c] += 1;
                
                let mut flag = true;
                for k in 0..26 {
                    if cnt[k] > 0 && cnt[k] != cnt[c] {
                        flag = false;
                        break;
                    }
                }
                
                if flag {
                    res = res.max((j - i + 1) as i32);
                }
            }
        }
        
        res
    }
}