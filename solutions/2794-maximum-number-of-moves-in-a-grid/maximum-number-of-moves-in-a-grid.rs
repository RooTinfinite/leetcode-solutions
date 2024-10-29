impl Solution {
    pub fn max_moves(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();    // number of rows
        let n = grid[0].len(); // number of columns
        
        let mut res = 0;
        let mut dp = vec![0; m];
        
        for j in 1..n {
            let mut left_top = 0;
            let mut found = false;
            
            for i in 0..m {
                let mut cur = -1;
                let next_left_top = dp[i];
                
                // Check move from top-left cell
                if i > 0 && left_top != -1 && grid[i][j] > grid[i - 1][j - 1] {
                    cur = cur.max(left_top + 1);
                }
                
                // Check move from direct left cell
                if dp[i] != -1 && grid[i][j] > grid[i][j - 1] {
                    cur = cur.max(dp[i] + 1);
                }
                
                // Check move from bottom-left cell
                if i + 1 < m && dp[i + 1] != -1 && grid[i][j] > grid[i + 1][j - 1] {
                    cur = cur.max(dp[i + 1] + 1);
                }
                
                dp[i] = cur;
                found = found || dp[i] != -1;
                left_top = next_left_top;
            }
            
            if !found {
                break;
            }
            res = j;
        }
        
        res as i32
    }
}