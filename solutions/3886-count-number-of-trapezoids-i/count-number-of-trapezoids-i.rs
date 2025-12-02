use std::collections::HashMap;

impl Solution {
    pub fn count_trapezoids(points: Vec<Vec<i32>>) -> i32 {
        let mut point_num: HashMap<i32, i32> = HashMap::new();
        let mod_val: i64 = 1000000007;
        let mut ans: i64 = 0;
        let mut sum: i64 = 0;
        
        for point in points {
            let y = point[1];
            *point_num.entry(y).or_insert(0) += 1;
        }
        
        for &p_num in point_num.values() {
            let edge = p_num as i64 * (p_num as i64 - 1) / 2;
            ans = (ans + edge * sum) % mod_val;
            sum = (sum + edge) % mod_val;
        }
        
        ans as i32
    }
}