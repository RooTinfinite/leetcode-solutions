class Solution:
    def maxValue(self, nums1: list[int], nums0: list[int]) -> int:
        MOD = 10**9 + 7

        def find(base, exp):
            res = 1
            base %= MOD
            while exp > 0:
                if exp % 2 == 1:
                    res = res * base % MOD
                base = base * base % MOD
                exp //= 2
            return res

        a = []
        last = 0

        for i in range(len(nums1)):
            if nums0[i] == 0:
                last += nums1[i]
            else:
                a.append((nums1[i], nums0[i]))

        a.sort(key=lambda x: (-x[0], x[1]))

        ans = 0
        exp = 0

        for i in range(len(a) - 1, -1, -1):
            one, zero = a[i]
            exp += zero
            first = find(2, exp)
            rn = find(2, one)
            val = first * ((rn - 1 + MOD) % MOD) % MOD
            ans = (ans + val) % MOD
            exp += one

        first = find(2, exp)
        rn = find(2, last)
        val = first * ((rn - 1 + MOD) % MOD) % MOD
        ans = (ans + val) % MOD

        return ans