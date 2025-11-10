impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut s: Vec<i32> = Vec::new();
        let mut res: i32 = 0;
        for a in nums {
            while s.last().map_or(false, |&x| x > a) {
                s.pop();
            }
            if a == 0 { continue; }
            if s.last().map_or(true, |&x| x < a) {
                res += 1;
                s.push(a);
            }
        }
        res
    }
}