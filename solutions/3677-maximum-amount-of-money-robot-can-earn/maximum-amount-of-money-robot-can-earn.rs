use std::cmp::{max, min};

impl Solution {
    pub fn maximum_amount(coins: Vec<Vec<i32>>) -> i32 {
        let m = coins.len();
        let n = coins[0].len();
        let mut memo = vec![vec![vec![i32::MIN; 3]; n]; m];
        
        fn dfs(coins: &Vec<Vec<i32>>, memo: &mut Vec<Vec<Vec<i32>>>, i: i32, j: i32, k: usize) -> i32 {
            let m = coins.len() as i32;
            let n = coins[0].len() as i32;
            
            if i >= m || j >= n {
                return i32::MIN;
            }

            let i_usize = i as usize;
            let j_usize = j as usize;
            let x = coins[i_usize][j_usize];
            
            // arrive at the destination
            if i == m - 1 && j == n - 1 {
                return if k > 0 { max(0, x) } else { x };
            }
            
            if memo[i_usize][j_usize][k] != i32::MIN {
                return memo[i_usize][j_usize][k];
            }
            
            // not neutralize
            let mut res = max(
                dfs(coins, memo, i + 1, j, k),
                dfs(coins, memo, i, j + 1, k)
            ) + x;
            
            if k > 0 && x < 0 {
                // neutralize
                res = max(
                    res,
                    max(
                        dfs(coins, memo, i + 1, j, k - 1),
                        dfs(coins, memo, i, j + 1, k - 1)
                    )
                );
            }
            
            memo[i_usize][j_usize][k] = res;
            res
        }
        
        dfs(&coins, &mut memo, 0, 0, 2)
    }
}