class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1        
        # otherwise we can move between top left and one neighbour back and forth until
        # we can move to the next cell
        m, n = len(grid), len(grid[0])
        directions = ((1, 0), (0, 1), (-1, 0), (0, -1))
        heap = [(0, m + n, 0)]  # (t, distance to goal d = m - i + n - j, i) , j = m + n - d - i
        min_time = [[math.inf]*n for _ in range(m)]
        min_time[0][0] = 0
        while True:
            t, d, i = heappop(heap)
            j = m + n - d - i
            if i == m - 1 and j == n - 1:
                return t           
            for di, dj in directions:
                ni, nj = i + di, j + dj
                if ni < 0 or nj < 0 or ni >= m or nj >= n:
                    continue
                dt = grid[ni][nj] - t 
                if dt <= 1:
                    nt = t + 1
                else:
                    nt = t + dt + (dt % 2 == 0) # move back and forth
                if min_time[ni][nj] <= nt:
                    continue
                min_time[ni][nj] = nt
                heappush(heap, (nt, d + i + j - ni - nj, ni))
        raise ValueError("Unreachable")


        
        