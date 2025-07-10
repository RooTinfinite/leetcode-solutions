class Solution:
    def getSmallestString(self, n: int, k: int) -> str:      
        s = [1]*n
        k -= n-1
        for i in range(n-1,-1,-1):
            val = min(26,k)
            s[i] = val
            k -= val - 1
            if k == 0:
                break
        string = [chr(ord("a")+i-1) for i in s]
        return "".join(string)