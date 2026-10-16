class Solution:
    def minRotations(self, s):
        def dist(a, b):
            x = abs(a - b)
            return min(x, 10 - x)

        total = 0
        last = 0

        for c in s:
            total += dist(last, int(c))
            last = int(c)

        return total