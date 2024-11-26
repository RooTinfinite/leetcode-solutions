from heapq import heappush, heappop

class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        DIR = ((-1, 0), (0, 1), (1, 0), (0, -1))
        
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
            
        n, m = len(grid), len(grid[0])
        q = [(0, 0, 0)]  # (time, x, y)
        visit = [[False] * m for _ in range(n)]
        visit[0][0] = True
        
        while q:
            t, x, y = heappop(q)
            
            for dx, dy in DIR:
                nx, ny = x + dx, y + dy
                
                if nx < 0 or nx >= n or ny < 0 or ny >= m or visit[nx][ny]:
                    continue

                nt = t + 1
                if grid[nx][ny] > nt:
                    nt += ((grid[nx][ny] - nt + 1) // 2) * 2

                if nx == n - 1 and ny == m - 1:
                    return nt
                    
                visit[nx][ny] = True
                heappush(q, (nt, nx, ny))
                
        return -1