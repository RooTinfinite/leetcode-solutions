class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        
        rows = len(grid)
        cols = len(grid[0])
        
        minHeap = []
        heappush(minHeap, (0, 0, 0))  # time, row(x), col(y)
        
        seen = [[0] * cols for _ in range(rows)]
        seen[0][0] = 1
        
        moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        while minHeap:
            curr_time, curr_row, curr_col = heappop(minHeap)
            
            if curr_row == rows - 1 and curr_col == cols - 1:
                return curr_time
            
            for dx, dy in moves:
                next_row = dx + curr_row
                next_col = dy + curr_col
                
                if (0 <= next_row < rows and 
                    0 <= next_col < cols and 
                    not seen[next_row][next_col]):
                    
                    wait_time = 1 if (grid[next_row][next_col] - curr_time) % 2 == 0 else 0
                    next_time = max(curr_time + 1, grid[next_row][next_col] + wait_time)
                    
                    heappush(minHeap, (next_time, next_row, next_col))
                    seen[next_row][next_col] = 1
        
        return -1