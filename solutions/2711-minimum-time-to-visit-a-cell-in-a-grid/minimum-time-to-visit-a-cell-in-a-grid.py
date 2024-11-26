from typing import List
from heapq import heappush, heappop

class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        
        rows, cols = len(grid), len(grid[0])
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]
        
        seen = [[False] * cols for _ in range(rows)]
        seen[0][0] = True
        
        pq = [(0, 0, 0)]  # time, row, col
        
        while pq:
            time, row, col = heappop(pq)
            
            if row == rows - 1 and col == cols - 1:
                return time
            
            for i in range(4):
                new_row = row + dx[i]
                new_col = col + dy[i]
                
                if (0 <= new_row < rows and 
                    0 <= new_col < cols and 
                    not seen[new_row][new_col]):
                    
                    next_time = max(time + 1, grid[new_row][new_col])
                    next_time += (next_time ^ (time + 1)) & 1
                    
                    heappush(pq, (next_time, new_row, new_col))
                    seen[new_row][new_col] = True
        
        return -1