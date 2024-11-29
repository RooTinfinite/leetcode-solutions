use std::collections::{BinaryHeap,HashSet};

type Grid = Vec<Vec<i32>>;
type Queue = BinaryHeap<(i32,(isize,isize))>;
type Visited = HashSet<(isize,isize)>;

impl Solution {
    pub fn minimum_time(grid: Grid) -> i32 {
        let mut queue:Queue = BinaryHeap::from_iter(vec![(0,(0,0))]);
        let mut result = i32::MAX;
        let mut visited:Visited = HashSet::from_iter(vec![(0,0)]);
        if grid[0][1] > 1 && grid[1][0] > 1 { return -1;}
        while !queue.is_empty() {
            let (time, (row,col)) = queue.pop().unwrap();
            let time = time*-1;
            if time > result { continue; }
            if row == grid.len() as isize - 1 && col == grid[0].len() as isize - 1 {
                result = result.min(time);
                continue;
            }   
            vec![(-1,0),(0,-1),(1,0),(0,1)].iter().for_each(|(add_r,add_c)| {
                process_cell(row+add_r, col+add_c, time, &grid, &mut queue, &mut visited);
            });       
        }

        fn process_cell(row:isize,col:isize,time:i32,grid:&Grid,queue: &mut Queue, visited:&mut Visited) {
            if row >= 0 && col >= 0 && row < grid.len() as isize && col < grid[0].len() as isize && !visited.contains(&(row,col)) {                
                if time+1 >= grid[row as usize][col as usize] {
                    queue.push(((time+1)*-1,(row,col)));
                } else {
                    let mut new_time = grid[row as usize][col as usize];
                    if (grid[row as usize][col as usize] - time) % 2 == 0 { new_time += 1;}                    
                    queue.push((new_time*-1,(row,col)));
                }
                visited.insert((row,col));
            };
        }
        result
    }
}