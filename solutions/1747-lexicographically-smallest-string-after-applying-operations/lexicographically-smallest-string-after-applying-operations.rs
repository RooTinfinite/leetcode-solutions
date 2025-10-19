impl Solution {
    pub fn find_lex_smallest_string(s: String, a: i32, b: i32) -> String {
        fn gcd(a: usize, b: usize) -> usize {
            let mut a = a;
            let mut b = b;
            while b != 0 {
                let temp = b;
                b = a % b;
                a = temp;
            }
            a
        }

        let n = s.len();
        let mut res = s.clone();
        let doubled = s.repeat(2);
        let g = gcd(b as usize, n);

        let mut add = |t: &mut Vec<char>, start: usize| {
            let original = t[start].to_digit(10).unwrap() as i32;
            let (mut min_val, mut times) = (10, 0);
            for i in 0..10 {
                let added = (original + i * a) % 10;
                if added < min_val {
                    min_val = added;
                    times = i;
                }
            }
            for i in (start..n).step_by(2) {
                let digit = t[i].to_digit(10).unwrap() as i32;
                t[i] = std::char::from_digit(((digit + times * a) % 10) as u32, 10).unwrap();
            }
        };

        for i in (0..n).step_by(g) {
            let mut t: Vec<char> = doubled[i..i+n].chars().collect();
            add(&mut t, 1);
            if b % 2 != 0 {
                add(&mut t, 0);
            }
            let t_str: String = t.into_iter().collect();
            if t_str < res {
                res = t_str;
            }
        }
        res
    }
}