class Solution:
    def checkGoodInteger(self, n: int) -> bool:

        ans = 0

        while n: 
            n, rem = divmod(n, 10)
            ans+= rem * (rem -1)
            if ans >= 50: return True

        return False
    