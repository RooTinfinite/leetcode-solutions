use std::collections::VecDeque;

impl Solution {
    pub fn can_reach(arr: Vec<i32>, start: i32) -> bool {
        let n = arr.len() as i32;

        let mut visited = vec![false; n as usize];
        let mut q = VecDeque::new();

        q.push_back(start);

        while let Some(i) = q.pop_front() {
            if i < 0 || i >= n || visited[i as usize] {
                continue;
            }

            if arr[i as usize] == 0 {
                return true;
            }

            visited[i as usize] = true;

            q.push_back(i + arr[i as usize]);
            q.push_back(i - arr[i as usize]);
        }

        false
    }
}