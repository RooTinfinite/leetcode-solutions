from collections import deque

class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m = len(maze)
        n = len(maze[0])

        queue = deque([(entrance[0], entrance[1], 0)]) # step 1
        maze[entrance[0]][entrance[1]] = "+" # step 2

        while queue:
            row, col, steps = queue.popleft() # step 3

            for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]: # step 4
                nr, nc = row + dy, col + dx
                if 0 <= nr < m and 0 <= nc < n and maze[nr][nc] == ".": # step 5
                    if (nr == 0 or nr == m - 1) or (nc == 0 or nc == n - 1):
                        return steps + 1

                    maze[nr][nc] = "+"
                    queue.append((nr, nc, steps + 1))

        return -1 # step 6
            
        