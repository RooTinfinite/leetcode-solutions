class Solution:
    def minMoves(self, matrix: List[str]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        pq = [(0, 0, 0)]

        directions = [(1,0), (-1,0), (0,1), (0,-1)]
        locations = [[] for _ in range(26)]

        for r in range(m):
            for c in range(n):
                if matrix[r][c] != '.' and matrix[r][c] != '#':
                    locations[ord(matrix[r][c]) - ord('A')].append((r, c))

        mask = 0
        visited = [[False] * n for _ in range(m)]

        while pq:
            moves, r, c = heapq.heappop(pq)
            if visited[r][c]:
                continue
            visited[r][c] = True
            if r == m - 1 and c == n - 1:
                return moves

            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and matrix[nr][nc] != '#' and not visited[nr][nc]:
                    heapq.heappush(pq, (moves + 1, nr, nc))

            bit = 1 << (ord(matrix[r][c]) - ord('A')) if matrix[r][c].isalpha() else 0
            if matrix[r][c].isalpha() and not (mask & bit):
                mask |= bit
                for x, y in locations[ord(matrix[r][c]) - ord('A')]:
                    if matrix[x][y] != '#' and not visited[x][y]:
                        heapq.heappush(pq, (moves, x, y))
        return -1