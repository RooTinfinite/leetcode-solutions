class Solution:
    def minFlips(self, s: str) -> int:
        f = [0, 0]

        for c in s:
            f[int(c)] += 1

        if not f[0] or not f[1]:
            return 0

        return min(
            f[0],
            f[1] - (int(s[0]) and int(s[-1])) - 1
        )