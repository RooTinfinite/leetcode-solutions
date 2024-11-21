class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        # Create a more efficient grid using a set for obstacles
        obstacles = set(map(tuple, guards + walls))
        guarded = set()
        
        # Process each guard's line of sight in all 4 directions
        for gx, gy in guards:
            # Check each direction: up, right, down, left
            for dx, dy in ((-1,0), (0,1), (1,0), (0,-1)):
                x, y = gx + dx, gy + dy
                
                # Continue in current direction until hitting boundary or obstacle
                while 0 <= x < m and 0 <= y < n and (x, y) not in obstacles:
                    guarded.add((x, y))
                    x += dx
                    y += dy
        
        # Calculate unguarded cells: total cells - (guards + walls + guarded cells)
        return m * n - len(obstacles) - len(guarded)
