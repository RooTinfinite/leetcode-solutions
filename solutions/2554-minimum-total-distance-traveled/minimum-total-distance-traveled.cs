public class Solution {
    public long MinimumTotalDistance(IList<int> robot, IList<IList<int>> factory) {
        // Convert to lists and sort
        var robots = robot.ToList();
        var factories = factory.ToList();
        robots.Sort();
        factories.Sort((a, b) => a[0].CompareTo(b[0]));
        
        int m = robots.Count;
        int n = factories.Count;
        
        // DP table initialization
        long[,] dp = new long[m + 1, n + 1];
        
        // Base case: if no factories left, distance is infinite
        for (int i = 0; i < m; i++) {
            dp[i, n] = long.MaxValue;
        }
        
        // Process each factory from right to left
        for (int j = n - 1; j >= 0; j--) {
            long prefix = 0;
            var qq = new LinkedList<(int pos, long val)>();
            qq.AddLast((m, 0));
            
            // Process each robot from right to left
            for (int i = m - 1; i >= 0; i--) {
                // Add distance to current factory
                prefix += Math.Abs((long)robots[i] - factories[j][0]);
                
                // Remove elements outside factory limit window
                while (qq.Count > 0 && qq.First.Value.pos > i + factories[j][1]) {
                    qq.RemoveFirst();
                }
                
                // Maintain monotonic queue property
                while (qq.Count > 0 && qq.Last.Value.val >= dp[i, j + 1] - prefix) {
                    qq.RemoveLast();
                }
                
                qq.AddLast((i, dp[i, j + 1] - prefix));
                dp[i, j] = qq.First.Value.val + prefix;
            }
        }
        
        return dp[0, 0];
    }
}