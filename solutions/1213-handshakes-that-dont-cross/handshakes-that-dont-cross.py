class Solution:
    def numberOfWays(self, num_people: int) -> int:
        MOD = 10**9 + 7

        @lru_cache(None)
        def dp(n):
            if n == 0:
                return 1
            if n == 2:
                return 1
            ans = 0
            for i in range(0, n, 2):
                ans += dp(i) * dp(n - 2 - i)
            return ans
        
        return dp(num_people) % MOD