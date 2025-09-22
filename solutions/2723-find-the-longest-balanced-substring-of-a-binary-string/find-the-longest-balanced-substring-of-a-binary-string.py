class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        res = 0
        it = 0
        while it < len(s):
            oCnt ,zCnt = 0 , 0
            while it < len(s) and s[it] == "0"  :
                zCnt += 1
                it += 1
            while it < len(s) and s[it] == "1":
                oCnt += 1
                it += 1
            res = max(res,2*min(oCnt,zCnt))
        return res