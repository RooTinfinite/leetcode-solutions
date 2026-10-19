impl Solution {
    pub fn target_indices(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut cnt1 = 0;  // Number of elements less than target
        let mut cnt2 = 0;  // Number of elements equal to target

        for &num in nums.iter() {
            if num < target {
                cnt1 += 1;
            } else if num == target {
                cnt2 += 1;
            }
        }

        let mut res = Vec::with_capacity(cnt2);
        for i in cnt1..cnt1 + cnt2 {
            res.push(i as i32);
        }
        res
    }
}