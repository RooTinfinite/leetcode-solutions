impl Solution {
    pub fn uniform_array(nums1: Vec<i32>) -> bool {
        let mut mn = nums1[0];
        let mut has_odd = false;
        for &v in &nums1 {
            if v < mn {
                mn = v;
            }
            if (v & 1) == 1 {
                has_odd = true;
            }
        }
        if (mn & 1) == 1 {
            return true;
        }
        return !has_odd;
    }
}