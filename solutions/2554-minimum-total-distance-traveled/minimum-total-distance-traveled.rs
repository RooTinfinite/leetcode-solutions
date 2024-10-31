impl Solution {
    pub fn minimum_total_distance(mut robot: Vec<i32>, mut factory: Vec<Vec<i32>>) -> i64 {
        robot.sort_unstable();
        factory.sort_unstable();
        
        let (m, n) = (robot.len(), factory.len());
        let mut dp = vec![vec![0i64; n + 1]; m + 1];
        
        // Base case: if no factories left, distance is infinite
        for i in 0..m {
            dp[i][n] = i64::MAX;
        }
        
        // Process each factory from right to left
        for j in (0..n).rev() {
            let mut prefix = 0i64;
            let mut qq = std::collections::VecDeque::new();
            qq.push_back((m, 0i64));
            
            // Process each robot from right to left
            for i in (0..m).rev() {
                // Add distance to current factory
                prefix += (robot[i] - factory[j][0]).abs() as i64;
                
                // Remove elements outside factory limit window
                while !qq.is_empty() && qq[0].0 > i + factory[j][1] as usize {
                    qq.pop_front();
                }
                
                // Maintain monotonic queue property
                while !qq.is_empty() && qq.back().unwrap().1 >= dp[i][j + 1] - prefix {
                    qq.pop_back();
                }
                
                qq.push_back((i, dp[i][j + 1] - prefix));
                dp[i][j] = qq[0].1 + prefix;
            }
        }
        
        dp[0][0]
    }
}