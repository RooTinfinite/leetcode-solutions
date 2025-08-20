class Solution:
    def countElements(self, nums: List[int]) -> int:
        return 0 if (len(nums) <= 2 or min(nums) == max(nums)) else len(nums) - (nums.count(min(nums)) + nums.count(max(nums)))