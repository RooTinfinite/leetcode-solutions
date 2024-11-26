impl Solution {
    pub fn find_champion(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut is_undefeated = vec![true; n];
        
        for edge in edges {
            let winner = edge[0] as usize;
            let loser = edge[1] as usize;
            is_undefeated[loser] = false;
        }
        
        let mut champion = -1;
        let mut champion_count = 0;
        
        for team in 0..n {
            if is_undefeated[team] {
                champion = team as i32;
                champion_count += 1;
            }
        }
        
        if champion_count == 1 { champion } else { -1 }
    }
}