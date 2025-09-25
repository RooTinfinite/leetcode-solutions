class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        winner = 0
        n = len(grid)
        for opponent in range(n):
            if opponent == winner:
                continue
            if grid[winner][opponent] == 0:
                winner = opponent
        return winner