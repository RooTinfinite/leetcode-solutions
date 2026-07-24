impl Solution {
    pub fn unique_xor_triplets(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let max_val = nums.iter().max().copied().unwrap_or(0) as usize;
        let mut u = 1;
        while u <= max_val {
            u <<= 1;
        }
        let mut s = vec![false; u];
        for i in 0..n {
            for j in i..n {
                s[(nums[i] ^ nums[j]) as usize] = true;
            }
        }
        let mut t = vec![false; u];
        for x in 0..u {
            if !s[x] {
                continue;
            }
            for &v in &nums {
                t[x ^ v as usize] = true;
            }
        }
        t.iter().filter(|&&b| b).count() as i32
    }
}