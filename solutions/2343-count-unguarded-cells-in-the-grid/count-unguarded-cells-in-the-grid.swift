class Solution {
    func countUnguarded(_ m: Int, _ n: Int, _ guards: [[Int]], _ walls: [[Int]]) -> Int {
        // Initialize grid with zeros
        var g = Array(repeating: Array(repeating: 0, count: n), count: m)
        
        // Mark guards and walls as 2
        for e in guards {
            g[e[0]][e[1]] = 2
        }
        for e in walls {
            g[e[0]][e[1]] = 2
        }
        
        // Directions: up, right, down, left
        let dirs = [-1, 0, 1, 0, -1]
        
        // Process each guard's line of sight
        for e in guards {
            for k in 0..<4 {
                var x = e[0], y = e[1]
                let dx = dirs[k], dy = dirs[k + 1]
                
                // Check cells in current direction until hitting boundary or obstacle
                while x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && g[x + dx][y + dy] < 2 {
                    x += dx
                    y += dy
                    g[x][y] = 1
                }
            }
        }
        
        // Count unguarded cells (cells with value 0)
        return g.reduce(0) { $0 + $1.filter { $0 == 0 }.count }
    }
}