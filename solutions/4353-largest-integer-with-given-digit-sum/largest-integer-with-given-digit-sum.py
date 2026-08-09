class Solution:
    def largestInteger(self, n: int, s: int) -> int:
        res = 0
        while s > 0:
            if n == 0:
                return -1
            n -= 1
            d = min(s, 9)
            res = res * 10 + d
            s -= d
        return res * 10**n