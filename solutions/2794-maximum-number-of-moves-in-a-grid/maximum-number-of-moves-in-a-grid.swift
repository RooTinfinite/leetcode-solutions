class Solution {
    func maxMoves(_ grid: [[Int]]) -> Int {
        let m = grid.count
        let n = grid[0].count  
        
        var res = 0
        
        var dp = Array(repeating: 0, count: m)
        
        for j in 1..<n {

            var leftTop = 0
            var found = false
            
            for i in 0..<m {

                var cur = -1
                let nxtLeftTop = dp[i]
                
                if i - 1 >= 0 && leftTop != -1 && grid[i][j] > grid[i-1][j-1] {
                    cur = max(cur, leftTop + 1)
                }
                
                if dp[i] != -1 && grid[i][j] > grid[i][j-1] {
                    cur = max(cur, dp[i] + 1)
                }
                
                if i + 1 < m && dp[i+1] != -1 && grid[i][j] > grid[i+1][j-1] {
                    cur = max(cur, dp[i+1] + 1)
                }
                
                dp[i] = cur
                found = found || (dp[i] != -1)
                leftTop = nxtLeftTop
            }
            
            if !found { break }
            res = j
        }
        
        return res
    }
}