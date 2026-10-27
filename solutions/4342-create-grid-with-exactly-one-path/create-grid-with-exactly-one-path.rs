impl Solution {
    pub fn create_grid(m: i32, n: i32) -> Vec<String> {
        let m = m as usize;
        let n = n as usize;
        let mut grid = Vec::with_capacity(m);

        grid.push(".".repeat(n));
        let row = "#".repeat(n - 1) + ".";
        for _ in 1..m {
            grid.push(row.clone());
        }

        grid
    }
}