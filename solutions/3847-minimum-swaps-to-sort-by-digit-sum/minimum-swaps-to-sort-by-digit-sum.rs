impl Solution {
    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut digit_sum = vec![0; n];
        for i in 0..n {
            let mut x = nums[i];
            let mut sum = 0;
            while x > 0 {
                sum += x % 10;
                x /= 10;
            }
            digit_sum[i] = sum;
        }

        let mut indices: Vec<usize> = (0..n).collect();
        indices.sort_by_key(|&i| (digit_sum[i], nums[i]));

        let mut target_pos = vec![0; n];
        for (pos, &idx) in indices.iter().enumerate() {
            target_pos[idx] = pos;
        }

        let mut visited = vec![false; n];
        let mut cycles = 0;
        for i in 0..n {
            if !visited[i] {
                cycles += 1;
                let mut j = i;
                while !visited[j] {
                    visited[j] = true;
                    j = target_pos[j];
                }
            }
        }

        (n - cycles) as i32
    }
}