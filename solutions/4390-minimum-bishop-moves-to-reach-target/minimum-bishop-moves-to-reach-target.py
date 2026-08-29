class Solution:
    def minBishopMoves(self, x, y):
        if abs(x[0] - y[0]) == abs(y[1] - x[1]):
            return 1

        if (x[0] + x[1]) % 2 == (y[0] + y[1]) % 2:
            return 2

        return -1