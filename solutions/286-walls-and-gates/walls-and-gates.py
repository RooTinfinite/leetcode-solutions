class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        queue = deque([])
        for i in range(len(rooms)):
            for j in range(len(rooms[0])):
                if rooms[i][j] == 0:
                    queue.append([i, j])
        while queue:
            i, j = queue.popleft()
            for r, c in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                if 0 <= r < len(rooms) and 0 <= c < len(rooms[0]) and rooms[r][c] == 2147483647:
                    rooms[r][c] = rooms[i][j] + 1
                    queue.append([r, c])