class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if min(grid[0][1],grid[1][0])>1: return -1
        
        m,n=len(grid),len(grid[0])
        q, seen = [(0,0,0)], set([(0,0)])

        while q:
            time,x,y=heapq.heappop(q)
            if (x,y)==(m-1,n-1): return time
            neighbours=[(x-1,y),(x+1,y),(x,y-1),(x,y+1)]
            for a,b in neighbours:
                if (a,b) in seen or a<0 or a==m or b<0 or b==n: continue
                seen.add((a,b))
                heapq.heappush(q,(max(time+1,grid[a][b]+(1-(grid[a][b]-time)%2)),a,b))