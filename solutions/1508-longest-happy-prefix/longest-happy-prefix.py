class Solution:
    def make_lps(self, pat):
        m = len(pat)
        lps = [0] * m
        i, length = 1, 0
        while i < m:
            if pat[i] == pat[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        return lps

    def longestPrefix(self, s: str) -> str:
        lps = self.make_lps(s)
        last = lps[-1]
        if last == 0:
            return ""
        else:
            return s[:last]        