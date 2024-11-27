impl Solution {
    fn update_distances(graph: &Vec<Vec<usize>>, current: usize, distances: &mut Vec<usize>) {
        let new_dist = distances[current] + 1;
        
        for &neighbor in &graph[current] {
            if distances[neighbor] <= new_dist {
                continue;
            }
            
            distances[neighbor] = new_dist;
            Self::update_distances(graph, neighbor, distances);
        }
    }

    pub fn shortest_distance_after_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as usize;
        let mut distances: Vec<usize> = (0..n).map(|i| n - 1 - i).collect();
        
        let mut graph: Vec<Vec<usize>> = vec![Vec::new(); n];
        for i in 0..n-1 {
            graph[i + 1].push(i);
        }
        
        let mut answer = Vec::new();
        
        for query in queries {
            let source = query[0] as usize;
            let target = query[1] as usize;
            
            graph[target].push(source);
            distances[source] = distances[source].min(distances[target] + 1);
            Self::update_distances(&graph, source, &mut distances);
            
            answer.push(distances[0] as i32);
        }
        
        answer
    }
}