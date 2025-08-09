class Solution:
    def memLeak(self, m1: int, m2: int) -> List[int]:
        res = [1,m1,m2]
        while 1:
            if res[2] > res[1]:
                mx = 2
            else:
                mx = 1
            if res[0] > res[mx]:
                return res
            else:
                res[mx] -= res[0]
            res[0]+=1