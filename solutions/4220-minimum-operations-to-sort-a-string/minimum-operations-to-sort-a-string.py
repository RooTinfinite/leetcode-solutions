class Solution:
    def minOperations(self, s: str) -> int:

        if len(s) == 2 and s[0] > s[1]:
            return -1                       #  ans = -1

        for ch1, ch2 in pairwise(s):
            if ch1 > ch2: break
        else: return 0                      #   ans = 0

        mn, mx = min(s[1:-1]), max(s[1:-1])
        lft, rgt = s[0], s[~0]

        if lft <= min(rgt, mn) or rgt >= max(lft, mx):
            return 1                        #   ans = 1

        elif rgt >= mn or lft <= mx:
            return 2                        #   ans = 2

        else: return 3                      #   ans = 3