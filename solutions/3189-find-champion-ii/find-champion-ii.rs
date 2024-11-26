impl Solution {
    pub fn find_champion(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut incoming = vec![0; n];
        
        for edge in edges {
            incoming[edge[1] as usize] += 1;
        }
        
        let champions: Vec<i32> = incoming
            .iter()
            .enumerate()
            .filter(|(_, &count)| count == 0)
            .map(|(i, _)| i as i32)
            .collect();
            
        if champions.len() > 1 {
            -1
        } else {
            champions[0]
        }
    }
}