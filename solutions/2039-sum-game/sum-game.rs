impl Solution {
    pub fn sum_game(num: String) -> bool {
        let n = num.len();
        let half = n / 2;
        
        let get = |s: &str| -> (i32, i32) {
            let mut nn = 0;
            let mut qq = 0;
            for ch in s.chars() {
                if ch == '?' {
                    qq += 1;
                } else {
                    nn += ch.to_digit(10).unwrap() as i32;
                }
            }
            (nn, qq)
        };
        
        let (n0, q0) = get(&num[..half]);
        let (n1, q1) = get(&num[half..]);
        
        ((q0 + q1) % 2 == 1) || (n0 - n1 != (q1 - q0) * 9 / 2)
    }
}