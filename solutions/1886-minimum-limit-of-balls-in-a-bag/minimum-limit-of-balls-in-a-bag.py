class Solution:
    def minimumSize(self, nums: List[int], maxOps: int) -> int:
        l, h = 1, max(nums)
        while l < h:
            m = (l + h) // 2
            if sum((n - 1) // m for n in nums) <= maxOps: h = m
            else: l = m + 1
        return h