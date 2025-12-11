impl Solution {
    pub fn count_covered_buildings(n: i32, buildings: Vec<Vec<i32>>) -> i32 {
        let n_usize = n as usize;
        let mut max_row = vec![0; n_usize + 1];
        let mut min_row = vec![n + 1; n_usize + 1];
        let mut max_col = vec![0; n_usize + 1];
        let mut min_col = vec![n + 1; n_usize + 1];
        
        for p in &buildings {
            let x = p[0] as usize;
            let y = p[1] as usize;
            
            max_row[y] = max_row[y].max(x as i32);
            min_row[y] = min_row[y].min(x as i32);
            max_col[x] = max_col[x].max(y as i32);
            min_col[x] = min_col[x].min(y as i32);
        }
        
        let mut res = 0;
        for p in &buildings {
            let x = p[0] as usize;
            let y = p[1] as usize;
            
            if (x as i32) > min_row[y] && (x as i32) < max_row[y] && 
               (y as i32) > min_col[x] && (y as i32) < max_col[x] {
                res += 1;
            }
        }
        
        res
    }
}