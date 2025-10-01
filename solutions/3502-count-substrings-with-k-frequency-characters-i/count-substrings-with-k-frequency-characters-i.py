class Solution:
    def numberOfSubstrings(self, s: str, k: int) -> int:
        ans = 0
        l = 0
        d = {}
        for c in s:
            d[c] = d.get(c, 0) + 1
            while d[c] == k:
                d[s[l]] -= 1
                l += 1
            ans += l
        return ans