impl Solution {
    pub fn valid_arrangement(pairs: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        use std::collections::HashMap;
        
        let mut adjacency_list: HashMap<i32, Vec<i32>> = HashMap::with_capacity(pairs.len());
        let mut in_out_degree: HashMap<i32, i32> = HashMap::with_capacity(pairs.len() * 2);
        
        // Build graph and count in/out degrees
        for pair in &pairs {
            adjacency_list.entry(pair[0])
                .or_insert_with(Vec::new)
                .push(pair[1]);
            *in_out_degree.entry(pair[0]).or_default() += 1;
            *in_out_degree.entry(pair[1]).or_default() -= 1;
        }
        
        // Find starting node (head)
        let mut start_node = pairs[0][0];
        for (&node, &degree) in &in_out_degree {
            if degree == 1 {
                start_node = node;
                break;
            }
        }
        
        let mut path = Vec::with_capacity(pairs.len() + 1);
        let mut node_stack = vec![start_node];
        
        while !node_stack.is_empty() {
            if let Some(neighbors) = adjacency_list.get_mut(&node_stack[node_stack.len() - 1]) {
                if neighbors.is_empty() {
                    path.push(node_stack.pop().unwrap());
                } else {
                    let next_node = neighbors.pop().unwrap();
                    node_stack.push(next_node);
                }
            } else {
                path.push(node_stack.pop().unwrap());
            }
        }
        
        let mut arrangement = Vec::with_capacity(path.len() - 1);
        let path_size = path.len();
        
        for i in (1..path_size).rev() {
            arrangement.push(vec![path[i], path[i-1]]);
        }
        
        arrangement
    }
}