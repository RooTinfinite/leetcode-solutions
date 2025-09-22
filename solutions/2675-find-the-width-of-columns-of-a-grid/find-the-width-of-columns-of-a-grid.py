class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        widths = [0] * n  
        for j in range(n):
            for i in range(m):
                width = len(str(abs(grid[i][j])))
                if grid[i][j] < 0:
                    width += 1 
                widths[j] = max(widths[j], width)
        return widths