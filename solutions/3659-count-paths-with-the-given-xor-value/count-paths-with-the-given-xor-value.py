class Solution:
    def countPathsWithXorValue(self, grid: List[List[int]], k: int) -> int:
        mod = 1_000_000_007
        n = len(grid)
        m = len(grid[0])
        dp = [[[-1 for _ in range(20)] for _ in range(m)] for _ in range(n)]

        def f(i, j, curr):
            if i >= n or j >= m:
                return 0
            
            curr ^= grid[i][j]
            
            if i == n - 1 and j == m - 1:
                return 1 if curr == k else 0
            
            if dp[i][j][curr] != -1:
                return dp[i][j][curr]
            
            right = f(i, j + 1, curr) % mod
            down = f(i + 1, j, curr) % mod
            
            dp[i][j][curr] = (right + down) % mod
            return dp[i][j][curr]
        
        return f(0, 0, 0)