import math

class Solution:
    def countValidSequences(self, n: int, k: int) -> int:

        MOD = 10**9 + 7

        total = math.comb(n - 1, k - 1) % MOD

        odd = 0

        if (n - k) % 2 == 0:
            odd = math.comb((n - k) // 2 + k - 1, k - 1) % MOD

        return (total - odd) % MOD