class Solution:
    def colorGrid(self, n: int, m: int, sources: list[list[int]]) -> list[list[int]]:
        grid = [[0]*m for _ in range(n)]
        q = deque()

        total_colored = 0

        for r, c, color in sources:
            grid[r][c] = color
            total_colored += 1
            q.append((r, c))

        dr = [1, -1, 0, 0]
        dc = [0, 0, 1, -1]

        while q and total_colored < n*m:
            size = len(q)
            updates = {}

            for _ in range(size):
                r, c = q.popleft()

                for k in range(4):
                    nr = r + dr[k]
                    nc = c + dc[k]

                    if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] == 0:
                        updates[(nr, nc)] = max(
                            updates.get((nr, nc), 0),
                            grid[r][c]
                        )

            for (r, c), color in updates.items():
                grid[r][c] = color
                total_colored += 1
                q.append((r, c))

        return grid