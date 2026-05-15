class Solution:
    def numberOfCleanRooms(self, room: List[List[int]]) -> int:
        directions = [(0,1),(1,0),(0,-1),(-1,0)]
        n = len(room)
        m = len(room[0])

        x, y = 0, 0
        d = 0

        visited = set()

        while (x,y,d) not in visited:
            visited.add((x,y,d))
            dx, dy = directions[d]
            nx, ny = x+dx, y+dy

            if not(0<=nx<n and 0<=ny<m) or room[nx][ny] == 1:
                d = (d+1) % 4
            else:
                x = nx
                y = ny
        
        res = set()
        for spot in visited:
            res.add((spot[0],spot[1]))
        return len(res)

                
            
            