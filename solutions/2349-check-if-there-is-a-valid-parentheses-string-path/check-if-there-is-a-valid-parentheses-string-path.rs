impl Solution {
    pub fn has_valid_path(grid: Vec<Vec<char>>) -> bool {
        let n = grid.len();
        let m = grid[0].len();
        let path_len = n + m - 1;

        if path_len % 2 == 1 {
            return false;
        }
        if grid[0][0] != '(' || grid[n - 1][m - 1] != ')' {
            return false;
        }

        let mut dp = vec![vec![vec![false; path_len + 1]; m]; n];

        dp[0][0][1] = true;

        for i in 0..n {
            for j in 0..m {
                let change = if grid[i][j] == '(' { 1 } else { -1 };

                if i > 0 {
                    for balance in 0..=path_len {
                        if !dp[i - 1][j][balance] {
                            continue;
                        }

                        let next = balance as isize + change;

                        if next >= 0 {
                            dp[i][j][next as usize] = true;
                        }
                    }
                }

                if j > 0 {
                    for balance in 0..=path_len {
                        if !dp[i][j - 1][balance] {
                            continue;
                        }

                        let next = balance as isize + change;

                        if next >= 0 {
                            dp[i][j][next as usize] = true;
                        }
                    }
                }
            }
        }

        dp[n - 1][m - 1][0]
    }
}