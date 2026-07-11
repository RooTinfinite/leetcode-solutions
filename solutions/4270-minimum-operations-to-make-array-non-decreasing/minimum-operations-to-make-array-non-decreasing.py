class Solution:
    def minOperations(self, nums: list[int]) -> int:
        res=0
        for i in range(len(nums)-2,-1,-1):
            if nums[i]>nums[i+1]:
                res+=nums[i]-nums[i+1]
        return res