impl Solution {
    pub fn has_all_codes(s: String, k: i32) -> bool {
        let k = k as usize;
        let mut v = vec![false; 1 << k];
        let (mut n, mut count) = (0, 1 << k);
        let mask = (1 << k) - 1;
        for (i, &b) in s.as_bytes().iter().enumerate() {
            n = ((n << 1) & mask) + if b == b'1' { 1 } else { 0 };
            if i + 1 < k || v[n] {
                continue;
            }
            v[n] = true;
            count -= 1;
            if count == 0 {
                return true;
            }
        }
        false
    }
}