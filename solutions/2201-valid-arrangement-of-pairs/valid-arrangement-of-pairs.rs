impl Solution {
    pub fn valid_arrangement(pairs: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        use std::collections::{HashMap, VecDeque};
        
        let mut adj_list: HashMap<i32, Vec<i32>> = HashMap::with_capacity(pairs.len());
        let mut in_out_deg: HashMap<i32, i32> = HashMap::with_capacity(pairs.len() * 2);
        
        // Build optimized graph
        for pair in &pairs {
            adj_list.entry(pair[0])
                .or_insert_with(Vec::new)
                .push(pair[1]);
            *in_out_deg.entry(pair[0]).or_default() += 1;
            *in_out_deg.entry(pair[1]).or_default() -= 1;
        }
        
        // Find start efficiently
        let start_node = in_out_deg.iter()
            .find(|(_, &deg)| deg == 1)
            .map(|(&node, _)| node)
            .unwrap_or(pairs[0][0]);
        
        let mut path = Vec::with_capacity(pairs.len() + 1);
        let mut stack = vec![start_node];
        
        // Iterative DFS
        while let Some(&current) = stack.last() {
            if let Some(neighbors) = adj_list.get_mut(&current) {
                if let Some(next) = neighbors.pop() {
                    stack.push(next);
                } else {
                    path.push(stack.pop().unwrap());
                }
            } else {
                path.push(stack.pop().unwrap());
            }
        }
        
        // Build result efficiently
        let mut result = Vec::with_capacity(pairs.len());
        for window in path.windows(2).rev() {
            result.push(vec![window[1], window[0]]);
        }
        
        result
    }
}