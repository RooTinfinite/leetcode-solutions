class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        # swap corresponding rows within the k×k block
        for i in range(k // 2):
            top, bottom = x + i, x + k - 1 - i
            grid[top][y : y + k], grid[bottom][y : y + k] = (
                grid[bottom][y : y + k],
                grid[top][y : y + k],
            )
        return grid
