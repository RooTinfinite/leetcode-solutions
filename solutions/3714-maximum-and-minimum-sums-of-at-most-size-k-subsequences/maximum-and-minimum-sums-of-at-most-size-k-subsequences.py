from itertools import accumulate

M = 10 ** 9 + 7

frac = list(accumulate(range(1, 10**5 + 1), lambda x, y: x * y % M, initial=1))


def comb(n, k):
    if n < k:
        return 0
    return frac[n] * pow(frac[k], -1, M) * pow(frac[n - k], -1, M) % M


class Solution:
    def minMaxSums(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        res = 0
        s = 1  # sum_{t = 0}^{k - 1} comb(m, t) => S_m
        # S_m = 2 * S_{m - 1} - comb(m-1, k-1)
        for i in range(n):
            res += (nums[i] + nums[n - i - 1]) * s
            res %= M
            s = (2 * s - comb(i, k-1)) % M
        return res