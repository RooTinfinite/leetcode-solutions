func countUnguarded(m int, n int, guards [][]int, walls [][]int) int {
    grid := make([][]int, m)
    for i := range grid {
        grid[i] = make([]int, n)
    }
    // 0 = free, 1 = guard, 2 = wall, 3 = guardable
    
    for _, g := range guards {
        grid[g[0]][g[1]] = 1
    }
    for _, w := range walls {
        grid[w[0]][w[1]] = 2
    }
    
    markGuarded := func(r, c int) {
        for row := r + 1; row < m; row++ {
            if grid[row][c] == 1 || grid[row][c] == 2 {
                break
            }
            grid[row][c] = 3
        }
        for row := r - 1; row >= 0; row-- {
            if grid[row][c] == 1 || grid[row][c] == 2 {
                break
            }
            grid[row][c] = 3
        }
        for col := c + 1; col < n; col++ {
            if grid[r][col] == 1 || grid[r][col] == 2 {
                break
            }
            grid[r][col] = 3
        }
        for col := c - 1; col >= 0; col-- {
            if grid[r][col] == 1 || grid[r][col] == 2 {
                break
            }
            grid[r][col] = 3
        }
    }
    
    for _, g := range guards {
        markGuarded(g[0], g[1])
    }
    
    res := 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == 0 {
                res++
            }
        }
    }
    
    return res
}