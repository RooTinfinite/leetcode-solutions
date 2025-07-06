use std::collections::HashMap;

struct FindSumPairs {
    nums1: Vec<i32>,
    nums2: Vec<i32>,
    cnt: HashMap<i32, i32>,
}

impl FindSumPairs {
    fn new(nums1: Vec<i32>, nums2: Vec<i32>) -> Self {
        let mut cnt = HashMap::new();
        for &num in &nums2 {
            *cnt.entry(num).or_insert(0) += 1;
        }
        FindSumPairs { nums1, nums2, cnt }
    }
    
    fn add(&mut self, index: i32, val: i32) {
        let index = index as usize;
        let old_val = self.nums2[index];
        *self.cnt.entry(old_val).or_insert(0) -= 1;
        self.nums2[index] += val;
        *self.cnt.entry(self.nums2[index]).or_insert(0) += 1;
    }
    
    fn count(&self, tot: i32) -> i32 {
        let mut ans = 0;
        for &num in &self.nums1 {
            let rest = tot - num;
            ans += self.cnt.get(&rest).unwrap_or(&0);
        }
        ans
    }
}