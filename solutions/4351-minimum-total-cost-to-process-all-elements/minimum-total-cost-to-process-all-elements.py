# AI-converted version of the original C++ solution.
class Solution:
    def minimumCost(self, nums: List[int], k: int) -> int:
        ops = 0
        res = k

        for x in nums:
            if res < x:
                add = (x - res + k - 1) // k
                ops += add
                res += add * k
            res -= x

        MOD = 10**9 + 7

        if ops % 2 == 0:
            return ((ops // 2) % MOD) * ((ops + 1) % MOD) % MOD

        return (ops % MOD) * (((ops + 1) // 2) % MOD) % MOD