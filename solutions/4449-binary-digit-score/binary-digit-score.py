class Solution:
    def calculateScore(self, a: int, b: int) -> int:
        c = 0
        d = 0
        while a:
            c += a & 1
            a >>= 1
        while b:
            d += b & 1
            b >>= 1
        if c >= d:
            return c * d
        return d // c