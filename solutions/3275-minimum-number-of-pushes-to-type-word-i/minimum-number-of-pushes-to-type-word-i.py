class Solution(object):
    def minimumPushes(self, word):
        n = len(word)
        a, b = 0, n

        if b > 8:
            a += 8
        else:
            return a + b

        if b > 16:
            a += 8 * 2
        else:
            return a + (b - 8) * 2

        if b > 24:
            a += 8 * 3
        else:
            return a + (b - 16) * 3

        if b == 25:
            a += 4

        if b == 26:
            a += 8

        return a