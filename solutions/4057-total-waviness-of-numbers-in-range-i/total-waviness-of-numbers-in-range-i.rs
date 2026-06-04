impl Solution {
    pub fn total_waviness(num1: i32, num2: i32) -> i32 {
        // calculate the sum of fluctuation values of all numbers in [0, num]
        fn solve(num: i32) -> i64 {
            // if the number is less than 3, the fluctuation value is 0
            if num < 100 {
                return 0;
            }
            let s = num.to_string();
            let n = s.len();
            let chars: Vec<char> = s.chars().collect();
            
            // memoized search uses two independent arrays
            // memo_cnt[pos][x][y]: the number of valid filling schemes where the current position is pos, and the previous two positions are x, y
            let mut memo_cnt = vec![vec![vec![-1i64; 10]; 10]; 16];
            // memo_sum[pos][x][y]: the fluctuation value when the current position is pos and the two left digits are x and y
            let mut memo_sum = vec![vec![vec![-1i64; 10]; 10]; 16];
            
            fn dfs(
                pos: usize,
                prev: i32,
                curr: i32,
                is_limit: bool,
                is_leading: bool,
                n: usize,
                chars: &Vec<char>,
                memo_cnt: &mut Vec<Vec<Vec<i64>>>,
                memo_sum: &mut Vec<Vec<Vec<i64>>>,
            ) -> (i64, i64) {
                // end position
                if pos == n {
                    return (1, 0);
                }
                // only use memoization when not limited by an upper bound and not containing leading zeros
                if !is_limit && !is_leading && prev >= 0 && curr >= 0 {
                    let p = prev as usize;
                    let c = curr as usize;
                    if memo_cnt[pos][p][c] != -1 {
                        return (memo_cnt[pos][p][c], memo_sum[pos][p][c]);
                    }
                }
                
                // calculate the number of solutions and volatility value under current conditions
                let mut cnt = 0i64;
                let mut sum = 0i64;
                let up = if is_limit {
                    (chars[pos] as i32 - '0' as i32)
                } else {
                    9
                };
                for digit in 0..=up {
                    let new_leading = is_leading && (digit == 0);
                    // the previous number is updated to curr
                    let new_prev = curr;
                    // the current number is updated to digit
                    let new_curr = if new_leading { -1 } else { digit };
                    let (sub_cnt, sub_sum) = dfs(
                        pos + 1,
                        new_prev,
                        new_curr,
                        is_limit && (digit == up),
                        new_leading,
                        n,
                        chars,
                        memo_cnt,
                        memo_sum,
                    );
                    // only calculate the volatility value when there are no leading zeros
                    if !new_leading && prev >= 0 && curr >= 0 {
                        // when the value is a peak or a trough, update the current fluctuation value
                        if (prev < curr && curr > digit) || (prev > curr && curr < digit) {
                            sum += sub_cnt;
                        }
                    }
                    
                    cnt += sub_cnt;
                    sum += sub_sum;
                }
                
                if !is_limit && !is_leading && prev >= 0 && curr >= 0 {
                    // update the memoization array
                    let p = prev as usize;
                    let c = curr as usize;
                    memo_cnt[pos][p][c] = cnt;
                    memo_sum[pos][p][c] = sum;
                }
                
                (cnt, sum)
            }
            
            let (_, total_sum) = dfs(0, -1, -1, true, true, n, &chars, &mut memo_cnt, &mut memo_sum);
            total_sum
        }
        
        (solve(num2) - solve(num1 - 1)) as i32
    }
}