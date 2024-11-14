impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let mut left: i64 = 1;
        let mut right: i64 = *piles.iter().max().unwrap() as i64;
        
        while left < right {
            let mid = left + (right - left) / 2;
            
            if Self::can_eat_all(&piles, h, mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        left as i32
    }
    
    fn can_eat_all(piles: &Vec<i32>, h: i32, k: i64) -> bool {
        let mut hours: i64 = 0;
        for &pile in piles {
            hours += (pile as i64 + k - 1) / k;
            if hours > h as i64 { return false; }
        }
        true
    }
}