use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn assign_tasks(servers: Vec<i32>, tasks: Vec<i32>) -> Vec<i32> {
        // Busy servers, stored as pairs (t, idx)
        let mut busy: BinaryHeap<Reverse<(i32, usize)>> = BinaryHeap::new();
        // Idle servers, stored as pairs (w, idx)
        let mut idle: BinaryHeap<Reverse<(i32, usize)>> = BinaryHeap::new();

        for (i, &w) in servers.iter().enumerate() {
            idle.push(Reverse((w, i)));
        }

        let mut ts = 0;
        let mut ans = vec![0; tasks.len()];

        for (i, &task) in tasks.iter().enumerate() {
            ts = ts.max(i as i32);
            // Move servers with t<=ts from priority queue busy to priority queue idle one by one
            while let Some(&Reverse((t, idx))) = busy.peek() {
                if t <= ts {
                    busy.pop();
                    idle.push(Reverse((servers[idx], idx)));
                } else {
                    break;
                }
            }

            if idle.is_empty() {
                if let Some(&Reverse((t, _))) = busy.peek() {
                    ts = t;
                    while let Some(&Reverse((t, idx))) = busy.peek() {
                        if t <= ts {
                            busy.pop();
                            idle.push(Reverse((servers[idx], idx)));
                        } else {
                            break;
                        }
                    }
                }
            }

            if let Some(Reverse((_, idx))) = idle.pop() {
                ans[i] = idx as i32;
                busy.push(Reverse((ts + task, idx)));
            }
        }

        ans
    }
}