func minimumTotalDistance(robot []int, factory [][]int) int64 {
    // Sort positions for optimal matching
    sort.Ints(robot)
    sort.Slice(factory, func(i, j int) bool {
        return factory[i][0] < factory[j][0]
    })
    
    m, n := len(robot), len(factory)
    
    // Initialize DP table
    dp := make([][]int64, m+1)
    for i := range dp {
        dp[i] = make([]int64, n+1)
        if i < m {
            dp[i][n] = math.MaxInt64
        }
    }
    
    // Process each factory from right to left
    for j := n-1; j >= 0; j-- {
        var prefix int64
        qq := make([][2]int64, 0)
        qq = append(qq, [2]int64{int64(m), 0})
        
        // Process each robot from right to left
        for i := m-1; i >= 0; i-- {
            // Add distance to current factory
            prefix += int64(abs(robot[i] - factory[j][0]))
            
            // Remove elements outside factory limit window
            if qq[0][0] > int64(i+factory[j][1]) {
                qq = qq[1:]
            }
            
            // Maintain monotonic queue property
            curr := dp[i][j+1] - prefix
            for len(qq) > 0 && qq[len(qq)-1][1] >= curr {
                qq = qq[:len(qq)-1]
            }
            
            qq = append(qq, [2]int64{int64(i), curr})
            dp[i][j] = qq[0][1] + prefix
        }
    }
    
    return dp[0][0]
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}