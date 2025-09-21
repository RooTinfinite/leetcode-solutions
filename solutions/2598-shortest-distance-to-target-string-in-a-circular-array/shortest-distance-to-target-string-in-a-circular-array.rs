impl Solution {
    pub fn closest_target(W: Vec<String>, T: String, s: i32) -> i32 {
        let mut a = i32::MAX;
        let n = W.len() as i32;
        for (i, w) in W.iter().enumerate() {
            if *w == T {
                let d = (i as i32 - s).abs();
                a = a.min(d.min(n - d));
            }
        }
        if a == i32::MAX { -1 } else { a }
    }
}