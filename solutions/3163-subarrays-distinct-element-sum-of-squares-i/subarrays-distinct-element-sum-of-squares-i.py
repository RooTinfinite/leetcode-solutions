class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        sum = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums) + 1):
                subarray = nums[i:j]
                sum = sum + len(set(subarray)) * len(set(subarray)) 

        return sum