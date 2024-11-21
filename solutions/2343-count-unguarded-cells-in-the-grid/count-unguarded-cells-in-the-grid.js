var countUnguarded = function(m, n, guards, walls) {
    // Initialize grid with zeros
    const g = Array(m).fill().map(() => Array(n).fill(0));
    
    // Mark guards and walls as 2
    for (const [x, y] of guards) {
        g[x][y] = 2;
    }
    for (const [x, y] of walls) {
        g[x][y] = 2;
    }
    
    // Directions: up, right, down, left
    const dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]];
    
    // Process each guard's line of sight
    for (const [gx, gy] of guards) {
        for (const [dx, dy] of dirs) {
            let x = gx;
            let y = gy;
            while (true) {
                x += dx;
                y += dy;
                // Check cells in current direction until hitting boundary or obstacle
                if (x < 0 || x >= m || y < 0 || y >= n || g[x][y] === 2) {
                    break;
                }
                g[x][y] = 1;
            }
        }
    }
    
    // Count unguarded cells (cells with value 0)
    return g.reduce((sum, row) => sum + row.filter(cell => cell === 0).length, 0);
};