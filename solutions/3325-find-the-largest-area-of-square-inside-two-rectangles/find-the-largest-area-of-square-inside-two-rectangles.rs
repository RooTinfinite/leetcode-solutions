use std::cmp::{max, min};

impl Solution {
    pub fn largest_square_area(bottom_left: Vec<Vec<i32>>, top_right: Vec<Vec<i32>>) -> i64 {
        let n = bottom_left.len();
        let mut max_side = 0;

        for i in 0..n {
            for j in i + 1..n {
                let w = min(top_right[i][0], top_right[j][0]) - max(bottom_left[i][0], bottom_left[j][0]);
                let h = min(top_right[i][1], top_right[j][1]) - max(bottom_left[i][1], bottom_left[j][1]);

                max_side = max(max_side, min(w, h));
            }
        }

        (max_side as i64) * (max_side as i64)
    }
}