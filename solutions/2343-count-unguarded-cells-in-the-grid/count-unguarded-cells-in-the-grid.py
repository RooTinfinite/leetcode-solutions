class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:

        def fill_row(row, col):
            for i in range(col-1, -1, -1):
                if grid[row][i] == 2:
                    break
                grid[row][i] = 1

            for i in range(col+1, n):
                if grid[row][i] == 2:
                    break
                grid[row][i] = 1

            for i in range(row-1, -1, -1):
                if grid[i][col] == 2:
                    break
                grid[i][col] = 1

            for i in range(row+1, m):
                if grid[i][col] == 2:
                    break
                grid[i][col] = 1
            

        grid = [[0]*n for _ in range(m)]

        for x, y in walls:
            grid[x][y] = 2
        
        for x, y in guards:
            grid[x][y] = 2

        for x, y in guards:
            fill_row(x, y)

        return sum(row.count(0) for row in grid)

        