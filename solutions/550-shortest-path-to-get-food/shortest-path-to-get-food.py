class Solution:
    def getFood(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        q = collections.deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '*': 
                    q.append((i,j, 0)); break
            if q: break        
        while q:
            x, y, cnt = q.popleft()
            if grid[x][y] == 'X': continue
            elif grid[x][y] == '#': return cnt
            grid[x][y] = 'X'
            for i, j in [(x + _x, y + _y) for _x, _y in [(-1, 0), (1, 0), (0, -1), (0, 1)]]:
                if 0 <= i < m and 0 <= j < n and grid[i][j] != 'X':
                    q.append((i, j, cnt + 1))
        return -1                    