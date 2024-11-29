from heapq import heappush, heappop

class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
            
        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        
        # Distance matrix to store minimum time to reach each cell
        dist = [[float('inf')] * n for _ in range(m)]
        dist[0][0] = 0
        
        # Priority queue to store (time, row, col)
        pq = [(0, 0, 0)]
        
        while pq:
            time, row, col = heappop(pq)
            
            # If we reached the destination
            if row == m-1 and col == n-1:
                return time
            
            # If we've found a better path already
            if time > dist[row][col]:
                continue
                
            # Check all four directions
            for dx, dy in directions:
                new_row, new_col = row + dx, col + dy
                
                if 0 <= new_row < m and 0 <= new_col < n:
                    # Calculate wait time if needed
                    wait = 0
                    if grid[new_row][new_col] > time + 1:
                        # If we need to wait, we should wait until the next odd/even time
                        # that satisfies the condition
                        wait = grid[new_row][new_col] - (time + 1)
                        if wait % 2 == 1:
                            wait += 1
                            
                    new_time = time + 1 + wait
                    
                    if new_time < dist[new_row][new_col]:
                        dist[new_row][new_col] = new_time
                        heappush(pq, (new_time, new_row, new_col))
        
        return -1
