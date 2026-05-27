class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        last_low = {}
        first_up = {}
        for i, c in enumerate(word):
            if c.islower():
                last_low[c] = i
            else:
                if c not in first_up:
                    first_up[c] = i
        ans = 0
        for c in string.ascii_lowercase:
            if (
                c in last_low
                and c.upper() in first_up
                and last_low[c] < first_up[c.upper()]
            ):
                ans += 1
        return ans