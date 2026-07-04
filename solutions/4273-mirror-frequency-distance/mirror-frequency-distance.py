class Solution:
    def mirrorFrequency(self, s: str) -> int:
        f1 = [0] * 10
        f2 = [0] * 26

        for ch in s:
            if '0' <= ch <= '9':
                f1[ord(ch) - ord('0')] += 1
            else:
                f2[ord(ch) - ord('a')] += 1

        ans = 0

        for i in range(5):
            ans += abs(f1[i] - f1[9 - i])

        for i in range(13):
            ans += abs(f2[i] - f2[25 - i])

        return ans