class Solution:
    def visit(self, move: str, x: int, y: int) -> list[int]:
        if move == 'L':
            y -= 1
        elif move == 'R':
            y += 1
        elif move == 'U':
            x -= 1
        elif move == 'D':
            x += 1

        return [x, y]

    def lastVisitedCell(self, grid: list[list[str]]) -> list[int]:
        n, m = len(grid), len(grid[0])

        vis = [[0] * m for _ in range(n)]

        currCellX, currCellY = 0, 0

        while True:
            vis[currCellX][currCellY] = 1

            curr = self.visit(
                grid[currCellX][currCellY],
                currCellX,
                currCellY
            )

            x, y = curr[0], curr[1]

            if (x < 0 or x >= n or
                y < 0 or y >= m or
                vis[x][y]):
                break

            currCellX, currCellY = x, y

        return [currCellX, currCellY]