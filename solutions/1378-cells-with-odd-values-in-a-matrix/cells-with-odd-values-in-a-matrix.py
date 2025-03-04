class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        r = [0]*m
        c = [0]*n

        for [i, j] in indices:
            r[i]+=1
            c[j]+=1
        
        ce = 0
        co = 0

        for x in c:
            if x%2==1:
                co+=1
            else:
                ce+=1
        ans = 0
        for x in r:
            # print(x, ce, co)
            if x%2==0:
                ans += co
            else:
                ans += (n - co)
        return ans
        