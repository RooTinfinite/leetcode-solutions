impl Solution {
    pub fn decrypt(code: Vec<i32>, k: i32) -> Vec<i32> {
        if k == 0{
            return code.iter().map(|_| 0).collect();
        }

        let mut k = k;
        let mut code = code;
        if k < 0 {
            code.reverse();
            k = -k;
            (0..code.len()).map(|i| code.iter().cycle().skip(i+1).take(k as usize).sum()).rev().collect()
        } else {
            (0..code.len()).map(|i| code.iter().cycle().skip(i+1).take(k as usize).sum()).collect()
        }

        // (0..code.len()).map(|i| code.iter().cycle().skip(i+offset).take(k as usize).sum()).collect()
    }
}