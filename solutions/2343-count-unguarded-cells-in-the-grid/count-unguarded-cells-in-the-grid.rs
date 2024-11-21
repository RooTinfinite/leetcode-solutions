impl Solution {
    pub fn count_unguarded(m: i32, n: i32, guards: Vec<Vec<i32>>, walls: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (m as usize, n as usize);
        let mut grid = vec![vec![0; n]; m];
        // 0 = free, 1 = guard, 2 = wall, 3 = guardable

        for guard in guards.iter() {
            grid[guard[0] as usize][guard[1] as usize] = 1;
        }
        for wall in walls.iter() {
            grid[wall[0] as usize][wall[1] as usize] = 2;
        }

        fn mark_guarded(grid: &mut Vec<Vec<i32>>, r: usize, c: usize, m: usize, n: usize) {
            for row in (r + 1)..m {
                if grid[row][c] == 1 || grid[row][c] == 2 {
                    break;
                }
                grid[row][c] = 3;
            }
            for row in (0..r).rev() {
                if grid[row][c] == 1 || grid[row][c] == 2 {
                    break;
                }
                grid[row][c] = 3;
            }
            for col in (c + 1)..n {
                if grid[r][col] == 1 || grid[r][col] == 2 {
                    break;
                }
                grid[r][col] = 3;
            }
            for col in (0..c).rev() {
                if grid[r][col] == 1 || grid[r][col] == 2 {
                    break;
                }
                grid[r][col] = 3;
            }
        }

        for guard in guards.iter() {
            mark_guarded(&mut grid, guard[0] as usize, guard[1] as usize, m, n);
        }

        let mut res = 0;
        for row in grid.iter() {
            for &cell in row.iter() {
                if cell == 0 {
                    res += 1;
                }
            }
        }

        res
    }
}