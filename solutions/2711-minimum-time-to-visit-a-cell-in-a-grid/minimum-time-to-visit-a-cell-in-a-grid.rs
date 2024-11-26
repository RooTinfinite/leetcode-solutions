use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn minimum_time(grid: Vec<Vec<i32>>) -> i32 {
        let moves = [(-1, 0), (0, 1), (1, 0), (0, -1)];
        
        if grid[0][1] > 1 && grid[1][0] > 1 {
            return -1;
        }
        
        let (rows, cols) = (grid.len(), grid[0].len());
        let mut pq = BinaryHeap::new();
        let mut seen = vec![vec![false; cols]; rows];
        
        pq.push(Reverse((0, 0, 0))); // (time, row, col)
        seen[0][0] = true;
        
        while let Some(Reverse((time, row, col))) = pq.pop() {
            for &(dr, dc) in &moves {
                let new_row = row as i32 + dr;
                let new_col = col as i32 + dc;
                
                if new_row < 0 || new_row >= rows as i32 || 
                   new_col < 0 || new_col >= cols as i32 ||
                   seen[new_row as usize][new_col as usize] {
                    continue;
                }
                
                let mut new_time = time + 1;
                let cell_value = grid[new_row as usize][new_col as usize];
                
                if cell_value > new_time {
                    new_time += ((cell_value - time) / 2) * 2;
                }
                
                if new_row as usize == rows - 1 && new_col as usize == cols - 1 {
                    return new_time;
                }
                
                seen[new_row as usize][new_col as usize] = true;
                pq.push(Reverse((new_time, new_row as usize, new_col as usize)));
            }
        }
        
        -1
    }
}