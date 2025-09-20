class Solution:
    def maximumRows(self, mat: List[List[int]], cols: int) -> int:
        n,m = len(mat),len(mat[0])
        ans = 0

        def check(state,row,rowIncludedCount):
            nonlocal ans
            if row==n:
                if sum(state)<=cols:
                    ans = max(ans,rowIncludedCount)
                return
            
            check(state[::],row+1,rowIncludedCount)
            for j in range(m):
                if mat[row][j]==1:
                    state[j] = 1
            check(state,row+1,rowIncludedCount+1)
        
        check([0]*m,0,0)
        return ans