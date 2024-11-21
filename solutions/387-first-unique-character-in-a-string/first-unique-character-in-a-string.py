class Solution:
    def firstUniqChar(self, s: str) -> int:
        minIdx = float('inf')
        for c in range(ord('a'),ord('z') + 1):
            c = chr(c)
            if c in s:
                if s.index(c) == s.rindex(c):
                    minIdx = min(minIdx,s.index(c))
        return minIdx if minIdx != float('inf') else -1