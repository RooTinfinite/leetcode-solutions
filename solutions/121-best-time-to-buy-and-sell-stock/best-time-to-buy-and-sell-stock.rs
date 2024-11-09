impl Solution {
    pub fn max_profit(nums: Vec<i32>) -> i32 {
        let mut min_pro = i32::MAX;
        let mut max_pro = 0;
        for num in nums {
            min_pro = min_pro.min(num);
            max_pro = max_pro.max(num - min_pro);
        }
        max_pro
    }
}