class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        @cache
        def dp(odd, even, odd_remain):
            if odd == even == 0: return odd_remain == 0
            
            ret, a = 0, A[n - (odd + even)]
            if odd and odd_remain - a >= 0:
                ret += dp(odd - 1, even, odd_remain - a) * odd
            if even:
                ret += dp(odd, even - 1, odd_remain) * even

            return ret
            
        MOD = 1_000_000_007
        
        A = list(map(int, num))
        ss = sum(A)
        if ss & 1: return 0

        target, n = ss // 2, len(A)
        even, odd = n // 2, (n + 1) // 2

        A.sort(reverse=True)
        fac, freq = 1, Counter(A)
        for v in freq.values():
            fac *= factorial(v)
        
        return (dp(odd, even, target) // fac) % MOD
        