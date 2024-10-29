func maxMoves(grid [][]int) int {
    m := len(grid)    // number of rows
    n := len(grid[0]) // number of columns
    
    // res will store the rightmost column we can reach
    res := 0
    
    // dp array stores the maximum number of moves possible to reach each cell
    // in the current column we're processing
    dp := make([]int, m)
    
    // Iterate through each column from left to right (starting from column 1)
    for j := 1; j < n; j++ {
        // leftTop keeps track of the dp value from the cell above-left
        leftTop := 0
        // found indicates if we can reach any cell in current column
        found := false
        
        // Iterate through each row in current column
        for i := 0; i < m; i++ {
            // cur will store the maximum moves to reach current cell
            cur := -1
            // Store dp[i] for next iteration's leftTop
            nxtLeftTop := dp[i]
            
            // Check move from top-left cell (if valid)
            if i-1 >= 0 && leftTop != -1 && grid[i][j] > grid[i-1][j-1] {
                cur = max(cur, leftTop+1)
            }
            
            // Check move from direct left cell (if valid)
            if dp[i] != -1 && grid[i][j] > grid[i][j-1] {
                cur = max(cur, dp[i]+1)
            }
            
            // Check move from bottom-left cell (if valid)
            if i+1 < m && dp[i+1] != -1 && grid[i][j] > grid[i+1][j-1] {
                cur = max(cur, dp[i+1]+1)
            }
            
            // Update dp array for current cell
            dp[i] = cur
            // Update found flag if we can reach current cell
            found = found || (dp[i] != -1)
            // Update leftTop for next row's iteration
            leftTop = nxtLeftTop
        }
        
        // If we can't reach any cell in current column, break
        if !found {
            break
        }
        // Update result to current column if we can reach it
        res = j
    }
    
    // Return the maximum number of moves possible
    return res
}

// Helper function to find maximum of two integers
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}