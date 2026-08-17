impl Solution {
    fn stone_game_v(stone_value: Vec<i32>) -> i32 {
        let n = stone_value.len();
        let mut f = vec![vec![0; n]; n];
        let mut maxl = vec![vec![0; n]; n];
        let mut maxr = vec![vec![0; n]; n];
        
        for left in (0..n).rev() {
            maxl[left][left] = stone_value[left];
            maxr[left][left] = stone_value[left];
            let mut total = stone_value[left];
            let mut suml = 0;
            let mut i = left as i32 - 1;
            
            for right in (left + 1)..n {
                total += stone_value[right];
                
                while i + 1 < right as i32 && (suml + stone_value[(i + 1) as usize]) * 2 <= total {
                    suml += stone_value[(i + 1) as usize];
                    i += 1;
                }
                
                if left as i32 <= i {
                    f[left][right] = f[left][right].max(maxl[left][i as usize]);
                }
                
                if (i + 1) < right as i32 {
                    f[left][right] = f[left][right].max(maxr[(i + 2) as usize][right]);
                }
                
                if suml * 2 == total {
                    f[left][right] = f[left][right].max(maxr[(i + 1) as usize][right]);
                }
                
                maxl[left][right] = maxl[left][right - 1].max(total + f[left][right]);
                maxr[left][right] = maxr[left + 1][right].max(total + f[left][right]);
            }
        }
        
        f[0][n - 1]
    }
}