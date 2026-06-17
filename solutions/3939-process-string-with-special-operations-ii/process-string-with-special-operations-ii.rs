impl Solution {
    pub fn process_str(s: String, mut k: i64) -> char {
        let mut len: i64 = 0;
        for c in s.chars() {
            match c {
                '*' => {
                    if len > 0 {
                        len -= 1;
                    }
                }
                '#' => {
                    len *= 2;
                }
                '%' => {}
                _ => {
                    len += 1;
                }
            }
        }
        if k + 1 > len {
            return '.';
        }
        for c in s.chars().rev() {
            match c {
                '*' => {
                    len += 1;
                }
                '#' => {
                    if k + 1 > (len + 1) / 2 {
                        k -= len / 2;
                    }
                    len = (len + 1) / 2;
                }
                '%' => {
                    k = len - k - 1;
                }
                _ => {
                    if k + 1 == len {
                        return c;
                    }
                    len -= 1;
                }
            }
        }
        '.'
    }
}