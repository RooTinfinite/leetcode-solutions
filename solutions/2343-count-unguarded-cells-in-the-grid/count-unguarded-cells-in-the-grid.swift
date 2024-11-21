class Solution {
    func countUnguarded(_ m: Int, _ n: Int, _ guards: [[Int]], _ walls: [[Int]]) -> Int {
        var grid = Array(repeating: Array(repeating: 0, count: n), count: m)
        // 0 = free, 1 = guard, 2 = wall, 3 = guardable
        
        for guardPos in guards {
            grid[guardPos[0]][guardPos[1]] = 1
        }
        
        for wall in walls {
            grid[wall[0]][wall[1]] = 2
        }
        
        func markGuarded(_ r: Int, _ c: Int) {
            // Check downward
            for row in (r + 1)..<m {
                if grid[row][c] == 1 || grid[row][c] == 2 { break }
                grid[row][c] = 3
            }
            
            // Check upward
            for row in (0..<r).reversed() {
                if grid[row][c] == 1 || grid[row][c] == 2 { break }
                grid[row][c] = 3
            }
            
            // Check right
            for col in (c + 1)..<n {
                if grid[r][col] == 1 || grid[r][col] == 2 { break }
                grid[r][col] = 3
            }
            
            // Check left
            for col in (0..<c).reversed() {
                if grid[r][col] == 1 || grid[r][col] == 2 { break }
                grid[r][col] = 3
            }
        }
        
        for guardPos in guards {
            markGuarded(guardPos[0], guardPos[1])
        }
        
        var result = 0
        for row in grid {
            for cell in row {
                if cell == 0 {
                    result += 1
                }
            }
        }
        
        return result
    }
}