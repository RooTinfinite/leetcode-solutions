class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:

        m, n, ans = len(grid)-1, len(grid[0])-1, 0

        for i, j in product(range(1, m), range(1,n)):

                sm = ( grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1]
                                      + grid[i  ][j] + # <-- hourglass center
                       grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1] )

                if sm > ans: ans = sm

        return ans