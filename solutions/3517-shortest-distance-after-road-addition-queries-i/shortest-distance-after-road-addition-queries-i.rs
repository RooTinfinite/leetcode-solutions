use std::collections::{VecDeque, HashSet};

impl Solution {
    pub fn shortest_distance_after_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as usize;
        let mut adj: Vec<Vec<i32>> = (0..n).map(|i| vec![(i + 1) as i32]).collect();
        
        let shortest_path = |adj: &Vec<Vec<i32>>| -> i32 {
            let mut q = VecDeque::new();
            q.push_back((0, 0)); // node, length
            let mut visit = HashSet::new();
            visit.insert(0);
            
            while let Some((cur, length)) = q.pop_front() {
                if cur == (n - 1) as i32 {
                    return length;
                }
                
                for &nei in &adj[cur as usize] {
                    if !visit.contains(&nei) {
                        q.push_back((nei, length + 1));
                        visit.insert(nei);
                    }
                }
            }
            -1
        };
        
        let mut res = Vec::new();
        for query in queries {
            let (src, dst) = (query[0] as usize, query[1]);
            adj[src].push(dst);
            res.push(shortest_path(&adj));
        }
        res
    }
}