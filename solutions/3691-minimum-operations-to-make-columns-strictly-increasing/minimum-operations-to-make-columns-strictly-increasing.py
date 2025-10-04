class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        total_ops = 0
        for col in range(len(grid[0])):
            prev_val = -1
            for row in range(len(grid)):
                if grid[row][col] <= prev_val:
                    total_ops += prev_val - grid[row][col] + 1
                    prev_val += 1
                else:
                    prev_val = grid[row][col]
        return total_ops