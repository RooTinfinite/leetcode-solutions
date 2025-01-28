class Solution {
    public long minCost(int n, int[][] cost) {
        int[][] qwe = {{0, 1},{0, 2},{1, 0},{1, 2},{2, 0},{2, 1}};
        
        boolean[][] can = new boolean[6][6];
        for(int p1 = 0; p1 < 6; p1++) {
            for(int p2 = 0; p2 < 6; p2++) {
                int x1 = qwe[p1][0];
                int y1 = qwe[p1][1];
                int x2 = qwe[p2][0];
                int y2 = qwe[p2][1];
                if(x1 != x2 && y1 != y2) {
                    can[p1][p2] = true;
                }
            }
        }
        
        int m = n / 2;
        long[][] dp = new long[m][6];
        for(int p = 0; p < 6; p++) {
            int x = qwe[p][0];
            int y = qwe[p][1];
            dp[0][p] = cost[0][x] + cost[n - 1][y];
        }
        
        for(int i = 1; i < m; i++) {
            for(int p = 0; p < 6; p++) {
                dp[i][p] = Long.MAX_VALUE;
            }
            for(int p1 = 0; p1 < 6; p1++) {
                long prev = dp[i - 1][p1];
                if(prev == Long.MAX_VALUE) continue;
                
                for(int p2 = 0; p2 < 6; p2++) {
                    if(!can[p1][p2]) continue;
                    int x = qwe[p2][0];
                    int y = qwe[p2][1];
                    long costPair = cost[i][x] + cost[n - 1 - i][y];
                    long temp = prev + costPair;
                    if(temp < dp[i][p2]) {
                        dp[i][p2] = temp;
                    }
                }
            }
        }
        
        long ans = Long.MAX_VALUE;
        for(int p = 0; p < 6; p++) {
            ans = Math.min(ans, dp[m - 1][p]);
        }
        
        return ans;
    }
}