use std::collections::VecDeque;

impl Solution {
    pub fn shortest_subarray(nums: Vec<i32>, k: i32) -> i32 {
        let mut res = i32::MAX;
        let mut cur_sum: i64 = 0;
        let mut q: VecDeque<(i64, i32)> = VecDeque::new();

        for r in 0..nums.len() {
            cur_sum += nums[r] as i64;
            
            if cur_sum >= k as i64 {
                res = res.min((r + 1) as i32);
            }

            // Find the minimum valid window ending at r
            while !q.is_empty() && cur_sum - q.front().unwrap().0 >= k as i64 {
                let (_, end_idx) = q.pop_front().unwrap();
                res = res.min(r as i32 - end_idx);
            }

            // Validate the monotonic deque
            while !q.is_empty() && q.back().unwrap().0 > cur_sum {
                q.pop_back();
            }
            q.push_back((cur_sum, r as i32));
        }

        if res == i32::MAX { -1 } else { res }
    }
}