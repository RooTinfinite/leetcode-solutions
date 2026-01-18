impl Solution {
    pub fn largest_magic_square(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        // prefix sum of each row
        let mut rowsum = vec![vec![0; n]; m];
        for i in 0..m {
            rowsum[i][0] = grid[i][0];
            for j in 1..n {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
            }
        }
        // prefix sum of each column
        let mut colsum = vec![vec![0; n]; m];
        for j in 0..n {
            colsum[0][j] = grid[0][j];
            for i in 1..m {
                colsum[i][j] = colsum[i - 1][j] + grid[i][j];
            }
        }

        // enumerate edge lengths from largest to smallest
        for edge in (2..=m.min(n)).rev() {
            let edge = edge as i32;
            // enumerate the top-left corner position (i,j) of the square
            for i in 0..=(m as i32 - edge) {
                for j in 0..=(n as i32 - edge) {
                    let i = i as usize;
                    let j = j as usize;
                    // calculate the standard value
                    let stdsum = rowsum[i][j + edge as usize - 1] - if j > 0 { rowsum[i][j - 1] } else { 0 };
                    let mut check = true;
                    // check each row
                    for ii in i + 1..i + edge as usize {
                        let sum = rowsum[ii][j + edge as usize - 1] - if j > 0 { rowsum[ii][j - 1] } else { 0 };
                        if sum != stdsum {
                            check = false;
                            break;
                        }
                    }
                    if !check {
                        continue;
                    }
                    // check each column
                    for jj in j..j + edge as usize {
                        let sum = colsum[i + edge as usize - 1][jj] - if i > 0 { colsum[i - 1][jj] } else { 0 };
                        if sum != stdsum {
                            check = false;
                            break;
                        }
                    }
                    if !check {
                        continue;
                    }
                    // check the diagonal
                    let mut d1 = 0;
                    let mut d2 = 0;
                    for k in 0..edge as usize {
                        d1 += grid[i + k][j + k];
                        d2 += grid[i + k][j + edge as usize - 1 - k];
                    }
                    if d1 == stdsum && d2 == stdsum {
                        return edge;
                    }
                }
            }
        }
        1
    }
}