from typing import List
import heapq

class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        visited = [-1] * (m * n)
        q = []
        
        heapq.heappush(q, (0, 0))
        visited[0] = 0
        dir = [0, -1, 0, 1, 0]
        
        if grid[1][0] > 1 and grid[0][1] > 1:
            return -1
        
        while q:
            t, node = heapq.heappop(q)
            
            row = node // n
            col = node % n
            
            if row == m - 1 and col == n - 1:
                return t
                
            for j in range(4):
                new_row = row + dir[j]
                new_col = col + dir[j + 1]
                
                if new_row < 0 or new_row >= m or new_col < 0 or new_col >= n:
                    continue
                    
                val = new_row * n + new_col
                if visited[val] != -1:
                    continue
                
                if grid[new_row][new_col] <= t + 1:
                    visited[val] = t + 1
                elif (t + 1) % 2 != grid[new_row][new_col] % 2:
                    visited[val] = grid[new_row][new_col] + 1
                else:
                    visited[val] = grid[new_row][new_col]
                    
                heapq.heappush(q, (visited[val], val))
        
        return -1