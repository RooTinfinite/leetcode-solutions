func countUnguarded(m int, n int, guards [][]int, walls [][]int) int {
    // Initialize grid with zeros
    g := make([][]int, m)
    for i := range g {
        g[i] = make([]int, n)
    }
    
    // Mark guards and walls as 2
    for _, e := range guards {
        g[e[0]][e[1]] = 2
    }
    for _, e := range walls {
        g[e[0]][e[1]] = 2
    }
    
    // Directions: up, right, down, left
    dirs := []int{-1, 0, 1, 0, -1}
    
    // Process each guard's line of sight
    for _, e := range guards {
        for k := 0; k < 4; k++ {
            x, y := e[0], e[1]
            dx, dy := dirs[k], dirs[k+1]
            
            // Check cells in current direction until hitting boundary or obstacle
            for x+dx >= 0 && x+dx < m && y+dy >= 0 && y+dy < n && g[x+dx][y+dy] < 2 {
                x += dx
                y += dy
                g[x][y] = 1
            }
        }
    }
    
    // Count unguarded cells (cells with value 0)
    unguardedCount := 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if g[i][j] == 0 {
                unguardedCount++
            }
        }
    }
    
    return unguardedCount
}
