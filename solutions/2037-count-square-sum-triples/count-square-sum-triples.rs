impl Solution {
    pub fn count_triples(n: i32) -> i32 {
        let mut res = 0;
        // enumerate a and b
        for a in 1..= n {
            for b in 1..= n {
                // determine if it meets the requirements
                let c = ((a * a + b * b) as f64).sqrt().floor() as i32;
                if c <= n && c * c == a * a + b * b {
                    res += 1;
                }
            }
        }
        res
    }
}