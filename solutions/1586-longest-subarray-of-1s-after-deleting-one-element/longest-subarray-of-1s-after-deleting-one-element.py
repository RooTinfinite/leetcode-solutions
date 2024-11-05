class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        res, l, prefix = 0, 0, 0
        for r, n in enumerate(nums):
            prefix += n
            if prefix < r - l:
                prefix -= nums[l]
                l += 1
        return r - l