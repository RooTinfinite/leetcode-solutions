use std::collections::VecDeque;

impl Solution {
    pub fn find_safe_walk(grid: Vec<Vec<i32>>, health: i32) -> bool {
        let (m, n) = (grid.len(), grid[0].len());
        let dirs: [(i32, i32); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        let mut dis = vec![vec![i32::MAX; n]; m];
        let mut q = VecDeque::new();
        
        q.push_front((0usize, 0usize));
        dis[0][0] = grid[0][0];
        
        while let Some((cx, cy)) = q.pop_front() {
            // the first time it leaves the queue, the shortest distance is guaranteed
            if cx == m - 1 && cy == n - 1 {
                return true;
            }
            
            for (dx, dy) in dirs.iter() {
                let nx = cx as i32 + dx;
                let ny = cy as i32 + dy;
                if nx < 0 || ny < 0 || nx >= m as i32 || ny >= n as i32 {
                    continue;
                }
                
                let (nx, ny) = (nx as usize, ny as usize);
                let cost = dis[cx][cy] + grid[nx][ny];
                // pruning: the new distance does not meet health requirements
                if cost >= health {
                    continue;
                }
                
                if cost < dis[nx][ny] {
                    dis[nx][ny] = cost;
                    if grid[nx][ny] == 0 {
                        q.push_front((nx, ny));
                    } else {
                        q.push_back((nx, ny));
                    }
                }
            }
        }
        
        false
    }
}