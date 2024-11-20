class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        lim = {c: s.count(c) - k for c in 'abc'}
        if min(lim.values()) < 0: return -1
        cnt = {c: 0 for c in 'abc'}
        m = l = 0
        for r, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] > lim[c]: cnt[s[l]] -= 1; l += 1
            m = max(m, r - l + 1)
        return len(s) - m