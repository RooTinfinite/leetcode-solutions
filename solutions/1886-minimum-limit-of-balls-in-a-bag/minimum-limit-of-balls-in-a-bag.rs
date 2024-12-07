impl Solution {
    pub fn minimum_size(nums: Vec<i32>, max_ops: i32) -> i32 {
        let mut low = 1;
        let mut high = *nums.iter().max().unwrap();
        while low < high {
            let mid = (low + high) / 2;
            let ops = nums.iter().map(|&n| (n - 1) / mid).sum::<i32>();
            if ops <= max_ops { high = mid } else { low = mid + 1 }
        }
        high
    }
}