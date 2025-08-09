class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        cnt = 0
        for i in range(len(s) - 2):
            a, b, c = s[i], s[i+1], s[i+2]
            if a != b and a != c and b != c:
                cnt += 1
        return cnt