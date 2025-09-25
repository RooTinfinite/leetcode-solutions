class Solution:
    def stringCount(self, n: int) -> int:

        @cache
        def dp(i, l, e, t):
            if i == n:
                return int(l >= 1 and e >= 2 and t >= 1)

            s = 0
            for ch in ascii_lowercase:
                if ch == 'l' and l != 1:
                    s += dp(i + 1, l + 1, e, t)
                elif ch == 'e' and e != 2:
                    s += dp(i + 1, l, e + 1, t)
                elif ch == 't' and t != 1:
                    s += dp(i + 1, l, e, t + 1)
                else:
                    s += dp(i + 1, l, e, t)

            return s % (10**9 + 7)

        return dp(0, 0, 0, 0) % (10**9 + 7)