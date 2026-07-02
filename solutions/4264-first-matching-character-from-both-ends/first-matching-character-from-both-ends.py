class Solution:
    def firstMatchingIndex(self, s: str) -> int:

        n = (len(s) + 1)//2

        for i in range(n):
            if s[i] == s[~i]:
                return i

        return  -1
        