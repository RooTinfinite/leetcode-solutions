import heapq

class Solution:
    def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])

        result = []
        min_price, max_price = pricing        

        x, y = start
        in_progress = {(x, y)}
        q = deque()
        q.append((x, y, 0))
        while q:
            x, y, d = q.pop()
            if min_price <= grid[x][y] <= max_price:
                result.append((d, grid[x][y], x, y))

            for u, v in ((x - 1, y), (x, y - 1),
                         (x + 1, y), (x, y + 1)):
                if (
                    0 <= u < m and 0 <= v < n
                    and (u, v) not in in_progress
                    and grid[u][v] != 0
                ):
                    in_progress.add((u, v))
                    q.appendleft((u, v, d + 1))
        
        return [
            [x, y]
            for _, _, x, y in heapq.nsmallest(k, result)
        ]