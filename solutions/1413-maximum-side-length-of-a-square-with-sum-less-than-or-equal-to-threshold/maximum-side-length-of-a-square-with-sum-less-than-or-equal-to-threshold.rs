impl Solution {
    fn get_rect(P: &Vec<Vec<i32>>, x1: usize, y1: usize, x2: usize, y2: usize) -> i32 {
        P[x2][y2] - P[x1-1][y2] - P[x2][y1-1] + P[x1-1][y1-1]
    }

    pub fn max_side_length(mat: Vec<Vec<i32>>, threshold: i32) -> i32 {
        let m = mat.len();
        let n = mat[0].len();
        let mut P = vec![vec![0; n + 1]; m + 1];
        
        for i in 1..=m {
            for j in 1..=n {
                P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + mat[i-1][j-1];
            }
        }

        let r = m.min(n);
        let mut ans = 0;
        for i in 1..=m {
            for j in 1..=n {
                for c in (ans + 1)..=r {
                    if i + c - 1 <= m && j + c - 1 <= n && 
                       Self::get_rect(&P, i, j, i + c - 1, j + c - 1) <= threshold {
                        ans = c;
                    } else {
                        break;
                    }
                }
            }
        }
        ans as i32
    }
}