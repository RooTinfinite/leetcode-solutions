class Solution:
    def firstUniqueEven(self, nums: list[int]) -> int:
        n = Counter(nums)
        for i in range(len(nums)):
            if n[nums[i]] == 1 and nums[i]%2 == 0:
                return nums[i]
        return -1