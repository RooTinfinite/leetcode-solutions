impl Solution {
    pub fn paths_with_max_score(board: Vec<String>) -> Vec<i32> {
        const MOD: i32 = 1_000_000_007;
        let n = board.len();
        let board: Vec<Vec<char>> = board.iter().map(|s| s.chars().collect()).collect();
        let mut dp = vec![vec![(-1, 0); n]; n];
        dp[n - 1][n - 1] = (0, 1);

        for i in (0..n).rev() {
            for j in (0..n).rev() {
                if !(i == n - 1 && j == n - 1) && board[i][j] != 'X' {
                    Self::update(&mut dp, i, j, i + 1, j, n);
                    Self::update(&mut dp, i, j, i, j + 1, n);
                    Self::update(&mut dp, i, j, i + 1, j + 1, n);
                    if dp[i][j].0 != -1 {
                        dp[i][j].0 += if board[i][j] == 'E' { 0 } else { board[i][j] as i32 - '0' as i32 };
                    }
                }
            }
        }
        if dp[0][0].0 != -1 {
            vec![dp[0][0].0, dp[0][0].1 % MOD]
        } else {
            vec![0, 0]
        }
    }

    fn update(dp: &mut Vec<Vec<(i32, i32)>>, x: usize, y: usize, u: usize, v: usize, n: usize) {
        const MOD: i32 = 1_000_000_007;
        if u >= n || v >= n || dp[u][v].0 == -1 {
            return;
        }
        if dp[u][v].0 > dp[x][y].0 {
            dp[x][y] = dp[u][v];
        } else if dp[u][v].0 == dp[x][y].0 {
            dp[x][y].1 = (dp[x][y].1 + dp[u][v].1) % MOD;
        }
    }
}