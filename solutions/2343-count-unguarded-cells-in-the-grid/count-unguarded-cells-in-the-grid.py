class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        # Create grid: 0=empty, 1=guarded, 2=wall/guard
        grid = [[0] * n for _ in range(m)]
        
        # Mark walls and guards as 2
        for x, y in walls + guards:
            grid[x][y] = 2
            
        # For each guard, mark cells they can see
        for guard_x, guard_y in guards:
            # Look in all 4 directions: up, right, down, left
            for dx, dy in [(-1,0), (0,1), (1,0), (0,-1)]:
                x, y = guard_x, guard_y
                
                # Keep moving in current direction until hitting wall/guard/boundary
                while True:
                    x += dx
                    y += dy
                    
                    # Stop if we hit boundary
                    if x < 0 or x >= m or y < 0 or y >= n:
                        break
                    
                    # Stop if we hit wall or guard
                    if grid[x][y] == 2:
                        break
                        
                    # Mark cell as guarded
                    grid[x][y] = 1
        
        # Count remaining unguarded cells (still marked as 0)
        unguarded = 0
        for row in grid:
            unguarded += row.count(0)
            
        return unguarded
