impl Solution {
    fn mod1(i: i32, n: i32) -> i32 {
        i - ((-(if i >= n { 1 } else { 0 })) & n)
    }

    pub fn decrypt(mut code: Vec<i32>, k: i32) -> Vec<i32> {
        let n = code.len() as i32;
        
        if k < 0 {
            let mut s = 0;
            for i in (n + k)..n {
                s += code[i as usize];
            }
            
            for i in 0..n {
                code[i as usize] <<= 16;
            }
            
            for i in 0..n {
                let v = code[i as usize] >> 16;
                code[i as usize] += s;
                let j = Self::mod1(n + k + i, n);
                s += v - (code[j as usize] >> 16);
            }
            
            for i in 0..n {
                code[i as usize] &= 0x3FFF;
            }
            
        } else if k > 0 {
            let mut s = 0;
            for i in 0..k {
                s += code[i as usize];
            }
            
            for i in 0..n {
                code[i as usize] <<= 16;
            }
            
            for i in 0..n {
                let v = code[i as usize] >> 16;
                let j = Self::mod1(i + k, n);
                s += (code[j as usize] >> 16) - v;
                code[i as usize] += s;
            }
            
            for i in 0..n {
                code[i as usize] &= 0x3FFF;
            }
            
        } else {
            code.fill(0);
        }
        
        code
    }
}

