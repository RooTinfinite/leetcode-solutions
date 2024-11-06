impl Solution {
    pub fn can_sort_array(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut values = nums.clone();

        // Forward pass
        for i in 0..n-1 {
            if values[i] <= values[i + 1] {
                continue;
            } else {
                if values[i].count_ones() == values[i + 1].count_ones() {
                    values.swap(i, i + 1);
                } else {
                    return false;
                }
            }
        }

        // Backward pass
        for i in (1..n).rev() {
            if values[i] >= values[i - 1] {
                continue;
            } else {
                if values[i].count_ones() == values[i - 1].count_ones() {
                    values.swap(i, i - 1);
                } else {
                    return false;
                }
            }
        }

        true
    }
}