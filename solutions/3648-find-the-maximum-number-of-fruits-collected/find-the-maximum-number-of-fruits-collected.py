class Solution:
    def maxCollectedFruits(self, fruits: List[List[int]]) -> int:
        def val(i,j,dp):
            if 0<=i<n and 0<=j<n:
                return dp[i][j]
            return 0
        n = len(fruits)
        dpT = [[0]*n for _ in range(n)]
        dpT[0][n-1] = fruits[0][n-1]
        n = len(fruits)
        for i in range(1, n):
            for j in range(max(i+1,n-1-i),n):
                dpT[i][j] = fruits[i][j]+max(val(i-1,j-1,dpT), val(i-1,j,dpT), val(i-1,j+1,dpT))
        dpB = [[0]*n for _ in range(n)]
        dpB[n-1][0] = fruits[n-1][0]
        for j in range(1,n):
            for i in range(max(j+1,n-1-j), n):
                dpB[i][j] = fruits[i][j]+max(val(i,j-1,dpB), val(i-1,j-1,dpB), val(i+1,j-1,dpB))
        diag = sum([fruits[i][i] for i in range(n)])
        return dpT[n-2][n-1] + dpB[n-1][n-2] + diag
                
                
            