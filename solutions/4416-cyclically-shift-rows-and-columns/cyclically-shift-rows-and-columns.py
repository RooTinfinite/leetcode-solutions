class Solution:
    def cyclicShift(self, n: int, grid: list[list[int]], rowShift: list[int], colShift: list[int]) -> list[list[int]]:
        result = [[0] * n for _ in range(n)]
        for r, c in product(range(n), range(n)):
            nc = (c - rowShift[r] + n) % n
            nr = (r - colShift[nc] + n) % n
            result[nr][nc] = grid[r][c]

        return result