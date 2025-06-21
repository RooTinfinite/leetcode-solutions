impl Solution {
    pub fn min_subsequence(mut nums: Vec<i32>) -> Vec<i32> {
        nums.sort_unstable_by(|a, b| b.cmp(a));
        let total: i32 = nums.iter().sum();
        let mut result = Vec::new();
        let mut current_sum = 0;

        for num in nums {
            result.push(num);
            current_sum += num;
            if current_sum > total - current_sum {
                break;
            }
        }

        result
    }
}