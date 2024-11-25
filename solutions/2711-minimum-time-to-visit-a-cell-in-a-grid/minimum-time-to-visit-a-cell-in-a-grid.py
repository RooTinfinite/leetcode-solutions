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
            
            for dr, dc in DIRS:
                newRow, newCol = row + dr, col + dc
                
                if (newRow < 0 or newRow >= rows or 
                    newCol < 0 or newCol >= cols or 
                    seen[newRow][newCol]):
                    continue
                
                newTime = time + 1
                if grid[newRow][newCol] > newTime:
                    newTime += (grid[newRow][newCol] - time) // 2 * 2
                
                if newRow == rows - 1 and newCol == cols - 1:
                    return newTime
                    
                seen[newRow][newCol] = True
                heappush(pq, (newTime, newRow, newCol))
                
        return -1