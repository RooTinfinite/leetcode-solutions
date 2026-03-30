impl Solution {
    pub fn check_strings(s1: String, s2: String) -> bool {
        if s1.len() != s2.len() {
            return false;
        }

        let mut counts = [0; 256];
        let b1 = s1.as_bytes();
        let b2 = s2.as_bytes();

        for i in 0..b1.len() {
            let offset = (i & 1) << 7;
            counts[offset + b1[i] as usize] += 1;
            counts[offset + b2[i] as usize] -= 1;
        }

        counts.iter().all(|&count| count == 0)
    }
}