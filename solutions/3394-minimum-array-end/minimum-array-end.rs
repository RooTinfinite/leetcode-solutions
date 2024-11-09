impl Solution {
    pub fn min_end(mut n: i32, x: i32) -> i64 {
        let mut res = x as i64;
        let mut i = 0;
        n-=1;

        while n != 0 {
            if ((res >> i) & 1) == 0 {
                res += (n as i64 & 1) << i;
                n = n >> 1;            
            }
            i+=1;
        }

        res
    }
}