class Solution(object):
    def specialGrid(self, N):
        size = 1 << N
        grid = [[0] * size for _ in range(size)]
        for i in range(N):
            for r in range(size):
                for c in range(size):
                    temp = (r >> i) & 1
                    y    = (c >> i) & 1
                    if temp == 0:
                        grid[r][c] += ( (3 if y == 0 else 0) << (2 * i) )
                    else:
                        grid[r][c] += ( (2 if y == 0 else 1) << (2 * i) )
        return grid