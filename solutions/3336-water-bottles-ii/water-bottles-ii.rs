impl Solution {
    pub fn max_bottles_drunk(num_bottles: i32, num_exchange: i32) -> i32 {
        let a = 1.0;
        let b = (2 * num_exchange - 3) as f64;
        let c = (-2 * num_bottles) as f64;
        let delta = b * b - 4.0 * a * c;
        let t = ((-b + delta.sqrt()) / (2.0 * a)).ceil() as i32;
        num_bottles + t - 1
    }
}