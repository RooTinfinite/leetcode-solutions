class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        sum1 = 0
        for i in range(len(nums)):
                sum1 += nums[i]
        sum2 = 0
        for i in range(len(nums)):
                while(nums[i] != 0):
                        sum2 += nums[i]%10
                        nums[i] = nums[i]//10
        return abs(sum2-sum1)                