class Solution:
    def isAdjacentDiffAtMostTwo(self, s: str) -> bool:
        for i in range(len(s) - 1):
            if abs(ord(s[i]) - ord(s[i + 1])) > 2:
                return False

        return True