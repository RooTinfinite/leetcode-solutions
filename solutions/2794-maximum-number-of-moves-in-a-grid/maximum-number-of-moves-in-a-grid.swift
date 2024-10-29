class Solution {
    func maxMoves(_ grid: [[Int]]) -> Int {
        // Get dimensions of the grid
        let m = grid.count      // number of rows
        let n = grid[0].count   // number of columns
        
        // res will store the rightmost column we can reach
        var res = 0
        
        // dp array stores the maximum number of moves possible to reach each cell
        // in the current column we're processing
        var dp = Array(repeating: 0, count: m)
        
        // Iterate through each column from left to right (starting from column 1)
        for j in 1..<n {
            // leftTop keeps track of the dp value from the cell above-left
            var leftTop = 0
            // found indicates if we can reach any cell in current column
            var found = false
            
            // Iterate through each row in current column
            for i in 0..<m {
                // cur will store the maximum moves to reach current cell
                var cur = -1
                // Store dp[i] for next iteration's leftTop
                let nxtLeftTop = dp[i]
                
                // Check move from top-left cell (if valid)
                if i - 1 >= 0 && leftTop != -1 && grid[i][j] > grid[i-1][j-1] {
                    cur = max(cur, leftTop + 1)
                }
                
                // Check move from direct left cell (if valid)
                if dp[i] != -1 && grid[i][j] > grid[i][j-1] {
                    cur = max(cur, dp[i] + 1)
                }
                
                // Check move from bottom-left cell (if valid)
                if i + 1 < m && dp[i+1] != -1 && grid[i][j] > grid[i+1][j-1] {
                    cur = max(cur, dp[i+1] + 1)
                }
                
                // Update dp array for current cell
                dp[i] = cur
                // Update found flag if we can reach current cell
                found = found || (dp[i] != -1)
                // Update leftTop for next row's iteration
                leftTop = nxtLeftTop
            }
            
            // If we can't reach any cell in current column, break
            if !found { break }
            // Update result to current column if we can reach it
            res = j
        }
        
        // Return the maximum number of moves possible
        return res
    }
}