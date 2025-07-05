impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
      let mut rslt: Vec<i32> = Vec::with_capacity(nums.len());
      for i in 0..n {
        rslt.push(nums[i as usize]);
        rslt.push(nums[i as usize + n as usize]);
      }
      rslt
    }
}