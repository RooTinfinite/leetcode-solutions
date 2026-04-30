impl Solution {
    pub fn max_path_score(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let k = k as usize;

        let inf = i32::MIN / 2;
        let mut dp = vec![vec![vec![inf; k + 1]; n]; m];

        dp[0][0][0] = 0;

        for i in 0..m {
            for j in 0..n {
                for c in 0..=k {
                    if dp[i][j][c] == inf {
                        continue;
                    }

                    if i + 1 < m {
                        let val = grid[i + 1][j];
                        let cost = if val == 0 { 0 } else { 1 };
                        if c + cost <= k {
                            dp[i + 1][j][c + cost] =
                                dp[i + 1][j][c + cost].max(dp[i][j][c] + val);
                        }
                    }

                    if j + 1 < n {
                        let val = grid[i][j + 1];
                        let cost = if val == 0 { 0 } else { 1 };
                        if c + cost <= k {
                            dp[i][j + 1][c + cost] =
                                dp[i][j + 1][c + cost].max(dp[i][j][c] + val);
                        }
                    }
                }
            }
        }

        let mut ans = inf;
        for c in 0..=k {
            ans = ans.max(dp[m - 1][n - 1][c]);
        }

        if ans < 0 { -1 } else { ans }
    }
}