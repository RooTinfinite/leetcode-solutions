class Solution:
    def residuePrefixes(self, s: str) -> int:

        distinctChrs, ans = 0, 0                    # <-- 1
        isDistinct = [True] * 26

        ords = [ord(x) - 97 for x in s]             # <-- 2

        for i, ch in enumerate(ords):               # <-- 3
            distinctChrs+= isDistinct[ch]
            isDistinct[ch] = False
            ans += (distinctChrs == (i + 1)%3)

        return ans