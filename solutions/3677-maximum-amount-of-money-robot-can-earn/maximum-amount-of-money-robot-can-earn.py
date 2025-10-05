class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        m, n = len(coins), len(coins[0])
        dp = [[[-inf]*4 for _ in range(n)] for _ in range(m)]
        dp[0][0][2] = coins[0][0]
        if coins[0][0] < 0: dp[0][0][1] = 0
        for i in range(m): 
            for j in range(n): 
                for k in range(3): 
                    if i: dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + coins[i][j], dp[i-1][j][k+1])
                    if j: dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + coins[i][j], dp[i][j-1][k+1])
        return max(dp[m-1][n-1][k] for k in range(3))