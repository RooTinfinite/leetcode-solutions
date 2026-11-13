use std::collections::BinaryHeap;

impl Solution {
    pub fn count_non_decreasing_subarrays(nums: Vec<i32>, k: i32) -> i64 {
        let n = nums.len();
        let mut ans: i64 = 0;
        let mut operations: i64 = 0;
        // Maintain the window maximum with a priority queue
        let mut q: BinaryHeap<(i32, usize)> = BinaryHeap::new();
        // Record the set of elements covered by this index
        let mut cnt: Vec<Vec<usize>> = vec![Vec::new(); n];
        // Index of the first greater-or-equal element to the right
        let mut pos: Vec<usize> = vec![n; n];
        // Decreasing monotonic stack
        let mut st: Vec<usize> = Vec::new();

        let mut left = 0usize;
        for right in 0..n {
            // Maintain the monotonic stack
            while let Some(&top) = st.last() {
                if nums[right] >= nums[top] {
                    pos[top] = right;
                    st.pop();
                } else {
                    break;
                }
            }
            // The stack top is the nearest greater element to the left of nums[right]
            if let Some(&top) = st.last() {
                cnt[top].push(right);
            }
            st.push(right);

            // The priority queue front is the window maximum
            q.push((nums[right], right));
            // Adding nums[right] increases the operation count
            let max_val = q.peek().unwrap().0;
            operations += std::cmp::max(0, (max_val - nums[right]) as i64);

            // The minimum operation count exceeds k; shrink the window
            while operations > k as i64 {
                // Removing nums[left] from the window decreases the operation count
                for &i in &cnt[left] {
                    // Subtract the contribution
                    let pr = std::cmp::min(pos[i], right + 1);
                    operations -= ((nums[left] - nums[i]) as i64) * ((pr - i) as i64);
                }
                left += 1;
            }

            // Remove elements with indices less than left from the priority queue
            while let Some(&(_, idx)) = q.peek() {
                if idx < left {
                    q.pop();
                } else {
                    break;
                }
            }

            // There are right - left + 1 valid contiguous subarrays ending at right
            ans += (right - left + 1) as i64;
        }

        ans
    }
}