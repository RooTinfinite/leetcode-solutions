impl Solution {
    pub fn min_end(n: i32, x: i32) -> i64 {
        let mut result = x as i64;
        let mut remaining = (n - 1) as i64;
        let mut position: i64 = 1;
        
        while remaining != 0 {
            if (x as i64 & position) == 0 {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }
        
        result
    }
}