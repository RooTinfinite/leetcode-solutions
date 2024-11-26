class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        # Early exit check
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
            
        rows, cols = len(grid), len(grid[0])
        moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        # Use array instead of matrix for visited states - more memory efficient
        seen = set([(0, 0)])
        minHeap = [(0, 0, 0)]  # (time, row, col)
        
        while minHeap:
            curr_time, x, y = heappop(minHeap)
            
            # Target reached
            if x == rows - 1 and y == cols - 1:
                return curr_time
            
            for dx, dy in moves:
                nx, ny = x + dx, y + dy
                
                if (0 <= nx < rows and 
                    0 <= ny < cols and 
                    (nx, ny) not in seen):
                    
                    # Calculate next time more efficiently
                    next_time = curr_time + 1
                    if grid[nx][ny] > next_time:
                        # Add necessary waiting time
                        diff = grid[nx][ny] - next_time
                        next_time += (diff + 1) // 2 * 2
                    
                    seen.add((nx, ny))
                    heappush(minHeap, (next_time, nx, ny))
        
        return -1