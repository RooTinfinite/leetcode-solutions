class Solution:
    def maxOperations(self, s: str) -> int:
        x = 0
        c = 0
        n = len(s)
        for i in range(n):
            if s[i] == '1':
                c += 1
            elif s[i] == '0':
                if i == n - 1 or s[i + 1] == '1':
                    x += c
        return x