class Solution:
    def countEvenlyGoodIntegers(self, l: int, r: int) -> int:        
        def count(A):
            if A <= 0: return 0
            digits = list(map(int, str(A)))
            n = len(digits)
            @cache
            def dp(i, parity, tight, started):
                if i == n:
                    return int(started and parity == 0)
                last = digits[i] if tight else 9
                ans = 0
                for d in range(last + 1):
                    new_tight = tight and digits[i] == d
                    new_started = started or d > 0
                    new_parity = parity ^ int(new_started and d % 2 == 0)
                    ans += dp(i + 1, new_parity, new_tight, new_started)
                return ans
            return dp(0, 0, True, False)
        return count(r) - count(l - 1)