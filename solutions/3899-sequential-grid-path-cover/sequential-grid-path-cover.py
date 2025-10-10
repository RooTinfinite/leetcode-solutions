class Solution:
    def findPath(self, grid: List[List[int]], k: int) -> List[List[int]]:
        row, col = len(grid), len(grid[0])
        count = 0
        zero = {}
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 0:
                    zero[(i, j)] = count
                    count += 1
        top = (1 << count) - 1

        @lru_cache(None)
        def dp(mask, i, j, val):
            if grid[i][j] == 0 and mask & (1 << zero[(i, j)]):
                return False
            if grid[i][j] > 0 and grid[i][j] != val:
                return False
            if grid[i][j] == 0:
                mask |= (1 << zero[(i, j)])
            else:
                val += 1
            if val == k + 1 and mask == top:
                ans.append([i, j])
                return True
            for na, nb in [(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)]:
                if 0 <= na < row and 0 <= nb < col and dp(mask, na, nb, val):
                    ans.append([i, j])
                    return True
            return False

        for i in range(row):
            for j in range(col):
                ans = []
                if dp(0, i, j, 1):
                    return ans[::-1]

        return []