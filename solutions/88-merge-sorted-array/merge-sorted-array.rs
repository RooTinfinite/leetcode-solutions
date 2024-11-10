impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &Vec<i32>, n: i32) {
        for (j, i) in (m..m+n).enumerate() {
            nums1[i as usize] = nums2[j];
        }
        nums1.sort();
    }
}