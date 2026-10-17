class Solution:
    def countGoodStrings(self, n: int) -> int:
        MOD = 10**9 + 7

        # Returns (F(n), F(n+1)) using fast doubling
        def fib(n):
            if n == 0:
                return (0, 1)

            x, y = fib(n // 2)          # x = F(k), y = F(k+1)

            a = x * ((2 * y - x) % MOD) % MOD    # F(2k)
            b = (x * x + y * y) % MOD            # F(2k+1)

            if n % 2 == 0:
                return (a, b)
            return (b, (a + b) % MOD)

        return 2 * fib(n)[0] % MOD