class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        ct = 0
        for i in range(len(nums) - 1):
            if nums[i] >= nums[i + 1]:
                ct += 1
                if i > 0 and nums[i - 1] >= nums[i + 1]:
                    if i + 2 < len(nums) and nums[i] >= nums[i + 2]:
                        return False
        return ct <= 1