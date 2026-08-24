class Solution:
    def stoneGameVIII(self, s: List[int]) -> int:
        s, res = list(accumulate(s)), 0
        for i in range(len(s) - 1, 0, -1):
            res = s[i] if i == len(s) - 1 else max(res, s[i] - res)
        return res