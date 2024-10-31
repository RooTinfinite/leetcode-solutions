class Solution {
    func minimumTotalDistance(_ robot: [Int], _ factory: [[Int]]) -> Int {
        // Create mutable copies for sorting
        var robots = robot.sorted()
        var factories = factory.sorted { $0[0] < $1[0] }
        
        let m = robots.count
        let n = factories.count
        
        // DP table initialization
        var dp = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
        
        // Base case: if no factories left, distance is infinite
        for i in 0..<m {
            dp[i][n] = Int.max
        }
        
        // Process each factory from right to left
        for j in stride(from: n-1, through: 0, by: -1) {
            var prefix = 0
            var queue = [(Int, Int)]() // (index, value)
            queue.append((m, 0))
            
            // Process each robot from right to left
            for i in stride(from: m-1, through: 0, by: -1) {
                // Add distance to current factory
                prefix += abs(robots[i] - factories[j][0])
                
                // Remove elements outside factory limit window
                while !queue.isEmpty && queue[0].0 > i + factories[j][1] {
                    queue.removeFirst()
                }
                
                // Maintain monotonic queue property
                while !queue.isEmpty && queue.last!.1 >= dp[i][j+1] - prefix {
                    queue.removeLast()
                }
                
                queue.append((i, dp[i][j+1] - prefix))
                dp[i][j] = queue[0].1 + prefix
            }
        }
        
        return dp[0][0]
    }
}