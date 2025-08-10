from math import sqrt

class Solution:
    def countTriples(self, n: int) -> int:
        list = 0
        for a in range(1, n):
            for b in range(a + 1, n):
                c = sqrt(a**2 + b**2)
                if int(c) == c and c <= n:
                    list += 2
        return list