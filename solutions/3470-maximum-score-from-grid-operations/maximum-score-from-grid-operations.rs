use std::cmp::max;

impl Solution {
    pub fn maximum_score(grid: Vec<Vec<i32>>) -> i64 {
        let n = grid[0].len();
        if n == 1 {
            return 0;
        }

        let mut dp = vec![vec![vec![0i64; n + 1]; n + 1]; n];
        let mut prev_max = vec![vec![0i64; n + 1]; n + 1];
        let mut prev_suffix_max = vec![vec![0i64; n + 1]; n + 1];
        let mut col_sum = vec![vec![0i64; n + 1]; n];

        for c in 0..n {
            for r in 1..=n {
                col_sum[c][r] = col_sum[c][r - 1] + grid[r - 1][c] as i64;
            }
        }

        for i in 1..n {
            for curr_h in 0..=n {
                for prev_h in 0..=n {
                    if curr_h <= prev_h {
                        let extra_score = col_sum[i][prev_h] - col_sum[i][curr_h];
                        dp[i][curr_h][prev_h] = max(
                            dp[i][curr_h][prev_h],
                            prev_suffix_max[prev_h][0] + extra_score,
                        );
                    } else {
                        let extra_score = col_sum[i - 1][curr_h] - col_sum[i - 1][prev_h];
                        dp[i][curr_h][prev_h] = max(
                            dp[i][curr_h][prev_h],
                            max(
                                prev_suffix_max[prev_h][curr_h],
                                prev_max[prev_h][curr_h] + extra_score,
                            ),
                        );
                    }
                }
            }

            for curr_h in 0..=n {
                prev_max[curr_h][0] = dp[i][curr_h][0];
                for prev_h in 1..=n {
                    let penalty = if prev_h > curr_h {
                        col_sum[i][prev_h] - col_sum[i][curr_h]
                    } else {
                        0
                    };
                    prev_max[curr_h][prev_h] = max(
                        prev_max[curr_h][prev_h - 1],
                        dp[i][curr_h][prev_h] - penalty,
                    );
                }

                prev_suffix_max[curr_h][n] = dp[i][curr_h][n];
                for prev_h in (0..n).rev() {
                    prev_suffix_max[curr_h][prev_h] = max(
                        prev_suffix_max[curr_h][prev_h + 1],
                        dp[i][curr_h][prev_h],
                    );
                }
            }
        }

        let mut ans = 0i64;
        for k in 0..=n {
            ans = max(ans, max(dp[n - 1][n][k], dp[n - 1][0][k]));
        }

        ans
    }
}