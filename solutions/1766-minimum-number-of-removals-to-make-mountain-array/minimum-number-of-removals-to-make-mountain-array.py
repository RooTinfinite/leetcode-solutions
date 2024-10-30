class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        t, suf = [], [0] * n
        for i in range(n - 1, 0, -1):
            p = bisect_left(t, nums[i])
            if p < len(t):
                suf[i] = p
                t[p] = nums[i]
            else:
                suf[i] = len(t)
                t.append(nums[i])
        t, pre, res = [], 0, 0
        for i, x in enumerate(nums):
            p = bisect_left(t, x)
            if p < len(t):
                pre = p
                t[p] = x
            else:
                pre = len(t)
                t.append(x)
            if pre >= 1 and suf[i] >= 1:
                res = max(res, pre + suf[i] + 1)
        return n - res
        