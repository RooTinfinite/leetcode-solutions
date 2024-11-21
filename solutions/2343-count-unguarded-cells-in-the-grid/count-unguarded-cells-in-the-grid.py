class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grid = [[0] * n for _ in range(m)] # Initialize grid with zeros
        # Mark obstacles
        for x, y in guards + walls: # gx,gy - Guards/Walls position
            grid[x][y] = 2  
        # Process guards' vision
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        for gx, gy in guards:
            for dx, dy in directions: # dx, dy - movement direction offsets
                x, y = gx, gy
                # Check cells in current direction until hitting boundary or obstacle
                while 0 <= x + dx < m and 0 <= y + dy < n and grid[x + dx][y + dy] != 2:
                    x += dx
                    y += dy
                    grid[x][y] = 1
                    
        return sum(row.count(0) for row in grid) # Count unguarded cells (value 0)