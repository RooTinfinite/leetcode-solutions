class Solution:
    def numOfStrings(self, patterns: list[str], word: str) -> int:
        cnt = 0
        for pat in patterns:
            if pat in word:
                cnt += 1
        return cnt