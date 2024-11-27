impl Solution {
    pub fn shortest_distance_after_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as usize;
        let mut distances = (0..n).collect::<Vec<_>>();
        let mut successors = Vec::with_capacity(n);
        
        for i in 0..n {
            let capacity = if i < n-1 { 1 } else { 0 };
            successors.push(Vec::with_capacity(capacity + queries.len()));
            if i < n-1 {
                successors[i].push(i+1);
            }
        }
        
        let mut result = Vec::with_capacity(queries.len());
        let mut to_update = Vec::with_capacity(n);
        
        for query in &queries {
            let (source, target) = (query[0] as usize, query[1] as usize);
            successors[source].push(target);
            to_update.push((source, target));
            
            while let Some((u, v)) = to_update.pop() {
                if distances[v] <= distances[u] + 1 {
                    continue;
                }
                distances[v] = distances[u] + 1;
                to_update.extend(successors[v].iter().map(|&w| (v, w)));
            }
            
            result.push(distances[n-1] as i32);
        }
        
        result
    }
}