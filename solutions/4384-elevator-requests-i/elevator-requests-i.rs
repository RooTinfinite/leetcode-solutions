impl Solution {
    pub fn elevator_requests(n: i32, requests: Vec<i32>) -> i32 {
        let mut total = 0;
        let mut curr = 0;
        
        for &floor in &requests {
            total += (curr - floor).abs();
            curr = floor;
        }
        
        total
    }
}