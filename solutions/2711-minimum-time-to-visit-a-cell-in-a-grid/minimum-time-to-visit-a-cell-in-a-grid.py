class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        DIRS = ((-1, 0), (0, 1), (1, 0), (0, -1))
        
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        
        rows, cols = len(grid), len(grid[0])
        pq = [(0, 0, 0)]  # (time, row, col)
        seen = [[False] * cols for _ in range(rows)]
        seen[0][0] = True
        
        while pq:
            time, row, col = heappop(pq)
            
            if row == rows - 1 and col == cols - 1:
                return time
            
            for dr, dc in DIRS:
                newRow, newCol = row + dr, col + dc
                
                if (0 <= newRow < rows and 
                    0 <= newCol < cols and 
                    not seen[newRow][newCol]):
                    
                    waitTime = 1 if (grid[newRow][newCol] - time) % 2 == 0 else 0
                    newTime = max(time + 1, grid[newRow][newCol] + waitTime)
                    
                    seen[newRow][newCol] = True
                    heappush(pq, (newTime, newRow, newCol))
        
        return -1
