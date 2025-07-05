impl Solution {
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        nums.iter()
            .enumerate()
            .fold((-0xFFFFFFF, true), |(mut l, mut r), (i, x)| {
                if x.eq(&1) {
                    if !l.eq(&-0xFFFFFFF) {
                        if i as i32 - l - 1 < k { r = false }                   
                    } l = i as i32;
                } (l, r)
            }).1
    }
}