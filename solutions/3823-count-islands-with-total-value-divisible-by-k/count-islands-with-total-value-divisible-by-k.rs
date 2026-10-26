impl Solution {
    pub fn count_islands(mut grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let m = grid.len();
        let n = grid[0].len();

        fn dfs(grid: &mut [Vec<i32>], i: usize, j: usize) -> i64 {
            let mut sum = grid[i][j] as i64;
            grid[i][j] = 0;
            let dirs = [-1, 0, 1, 0, -1];
            for d in 0..4 {
                let x = i as i32 + dirs[d];
                let y = j as i32 + dirs[d + 1];
                if x >= 0 && x < grid.len() as i32
                    && y >= 0 && y < grid[0].len() as i32
                    && grid[x as usize][y as usize] > 0
                {
                    sum += dfs(grid, x as usize, y as usize);
                }
            }
            sum
        }

        let mut ans = 0;
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] > 0 && dfs(&mut grid, i, j) % k as i64 == 0 {
                    ans += 1;
                }
            }
        }

        ans
    }
}