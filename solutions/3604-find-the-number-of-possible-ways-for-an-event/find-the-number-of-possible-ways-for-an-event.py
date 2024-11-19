class Solution:
    def numberOfWays(self, n: int, x: int, y: int) -> int:
        MOD = (10 ** 9) + 7

        dp = [0] * (x + 1)
        dp[0] = 1

        for _ in range(n):
            dp2 = [0] * (x + 1)
            for k in range(x + 1):
                dp2[k] += dp[k] * k % MOD
                dp2[k] %= MOD
                if k < x:
                    dp2[k + 1] += dp[k] * (x - k) % MOD
                    dp2[k + 1] %= MOD
            dp = dp2
        
        ret, ypow  = 0, 1
        for k in range(x + 1):
            ret += ypow * dp[k] % MOD
            ret %= MOD
            ypow = ypow * y % MOD
        return ret