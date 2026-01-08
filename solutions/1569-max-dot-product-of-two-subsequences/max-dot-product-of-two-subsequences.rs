impl Solution {
    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let m = nums1.len();
        let n = nums2.len();
        let mut current = vec![i32::MIN; n + 1];
        let mut previous = vec![i32::MIN; n + 1];

        for i in 1..=m {
            for j in 1..=n {
                let curr_product = nums1[i - 1] * nums2[j - 1];
                current[j] = std::cmp::max(curr_product, std::cmp::max(previous[j], std::cmp::max(current[j - 1], curr_product + std::cmp::max(0, previous[j - 1]))));
            }
            std::mem::swap(&mut current, &mut previous);
        }
        previous[n]
    }
}