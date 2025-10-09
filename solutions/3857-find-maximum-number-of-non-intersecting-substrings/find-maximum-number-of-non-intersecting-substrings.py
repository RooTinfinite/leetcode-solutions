class Solution:
    def maxSubstrings(self, word: str) -> int:
        last = [0] * 26
        n = len(word)
        res = mask = 0
        for i in range(n):
            c = ord(word[i]) - ord('a')
            if (mask & (1 << c)) == 0:
                last[c] = i
                mask |= (1 << c)
            elif i - last[c] + 1 >= 4:
                res += 1
                mask = 0
        return res