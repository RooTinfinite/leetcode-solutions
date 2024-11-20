class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        re=start
        for i in range(1,n):
            ne=start+2*i
            re^=ne
        return re