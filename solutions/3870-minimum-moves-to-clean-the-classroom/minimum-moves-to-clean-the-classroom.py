from collections import deque

class Solution:
    def minMoves(self, classroom, energy):
        m = len(classroom)
        n = len(classroom[0])

        sr, sc = -1, -1
        cnt = 0

        # Give each litter an ID for bitmask
        id = [[-1] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if classroom[i][j] == 'S':
                    sr = i
                    sc = j
                if classroom[i][j] == 'L':
                    id[i][j] = cnt
                    cnt += 1

        masks = 1 << cnt
        fullMask = masks - 1

        # best[r][c][mask] = max energy reached at this state
        best = [[[-1] * masks for _ in range(n)] for _ in range(m)]

        q = deque()

        q.append((sr, sc, 0, energy, 0))
        best[sr][sc][0] = energy

        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]

        while q:
            r, c, mask, en, dist = q.popleft()

            # All litter collected
            if mask == fullMask:
                return dist

            # No energy, cannot move
            if en == 0:
                continue

            for d in range(4):

                nr = r + dr[d]
                nc = c + dc[d]

                # Outside grid
                if nr < 0 or nr >= m or nc < 0 or nc >= n:
                    continue

                # Obstacle
                if classroom[nr][nc] == 'X':
                    continue

                newEn = en - 1
                newMask = mask

                # Collect litter
                if classroom[nr][nc] == 'L':
                    newMask |= (1 << id[nr][nc])

                # Recharge
                if classroom[nr][nc] == 'R':
                    newEn = energy

                # Already reached with more energy
                if best[nr][nc][newMask] >= newEn:
                    continue

                best[nr][nc][newMask] = newEn

                q.append((nr, nc, newMask, newEn, dist + 1))

        return -1