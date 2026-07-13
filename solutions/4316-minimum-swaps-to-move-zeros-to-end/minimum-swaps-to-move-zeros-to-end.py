class Solution:
    def minimumSwaps(self, nums):
        return nums[:-nums.count(0)].count(0)