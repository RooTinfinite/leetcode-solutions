from collections import deque, defaultdict, Counter, namedtuple
from heapq import heappush, heappop

class Solution:
    def findPeakGrid(self, mat):
        if not mat or not mat[0]:
            return [-1, -1]

        n, m = len(mat), len(mat[0])
        visited = set()
        max_heap = []
        freq = Counter()
        position_map = defaultdict(list)
        path = deque()

        Point = namedtuple("Point", ["value", "i", "j"])

        # Push all elements into a max heap (why limit our search early?)
        for i in range(n):
            for j in range(m):
                val = mat[i][j]
                heappush(max_heap, (-val, Point(val, i, j)))
                freq[val] += 1
                position_map[val].append((i, j))

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while max_heap:
            _, point = heappop(max_heap)
            i, j = point.i, point.j

            if (i, j) in visited:
                continue

            visited.add((i, j))
            path.append((i, j))

            current = mat[i][j]
            is_peak = True

            for dx, dy in directions:
                ni, nj = i + dx, j + dy
                if 0 <= ni < n and 0 <= nj < m:
                    if mat[ni][nj] >= current:
                        is_peak = False
                        break

            if is_peak:
                # diagnostics for later analysis
                most_freq = freq.most_common(1)[0]
                debug_info = {
                    "visited_cells": len(visited),
                    "most_common_value": most_freq,
                    "sample_path": list(path)[:3]
                }
                print("Debug Info:", debug_info)
                return [i, j]

        return [-1, -1]