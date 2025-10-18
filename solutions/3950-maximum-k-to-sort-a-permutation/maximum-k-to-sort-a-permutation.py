class Solution:
    def sortPermutation(self, nums):
        mask = (1 << 30) - 1  # ~INT_MAX
        for i, val in enumerate(nums):
            if val != i:
                mask &= val
        return 0 if mask == (1 << 30) - 1 else mask