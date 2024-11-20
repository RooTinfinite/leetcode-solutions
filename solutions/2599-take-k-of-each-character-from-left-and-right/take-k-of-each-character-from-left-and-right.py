class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        limit = {char: s.count(char) - k for char in "abc"}
        if any(x < 0 for x in limit.values()):
            return -1
        cnts = {c: 0 for c in 'abc'}
        ans = l = 0
        for r, c in enumerate(s):
            cnts[c] += 1
            while cnts[c] > limit[c]:
                cnts[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return len(s) - ans