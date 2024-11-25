class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        visited = [[False] * n for _ in range(m)]
        heap = [(0, 0, 0)] # (t, r, c)
        while heap:
            t, r, c = heapq.heappop(heap)
            if r == m - 1 and c == n - 1:
                return t
            if visited[r][c]:
                continue
            visited[r][c] = True
            for dr, dc in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                nr, nc = r + dr, c + dc
                if nr < 0 or nr >= m or nc < 0 or nc >= n or visited[nr][nc]:
                    continue
                wait = (grid[nr][nc] - t) % 2 == 0
                nt = max(grid[nr][nc] + wait, t + 1)
                heapq.heappush(heap, (nt, nr, nc))
        return -1