impl Solution {
    pub fn separate_squares(squares: Vec<Vec<i32>>) -> f64 {
        let mut max_y: f64 = 0.0;
        let mut total_area: f64 = 0.0;
        
        for sq in &squares {
            let l = sq[2] as f64;
            total_area += l * l;
            max_y = max_y.max((sq[1] + sq[2]) as f64);
        }
        
        let mut lo = 0.0;
        let mut hi = max_y;
        let eps = 1e-5;
        while (hi - lo).abs() > eps {
            let mid = (hi + lo) / 2.0;
            if Self::check(mid, &squares, total_area) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        
        hi
    }
    
    fn check(limit_y: f64, squares: &Vec<Vec<i32>>, total_area: f64) -> bool {
        let mut area = 0.0;
        
        for sq in squares {
            let y = sq[1] as f64;
            let l = sq[2] as f64;
            if y < limit_y {
                let overlap = (limit_y - y).min(l);
                area += l * overlap;
            }
        }
        
        area >= total_area / 2.0
    }
}