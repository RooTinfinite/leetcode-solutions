class Solution:
    def sumOfGoodNumbers(self, nums, k):
        total_sum = 0
        n = len(nums)
        
        for i in range(n):
            is_good = True
            
            if i - k >= 0:
                if nums[i] <= nums[i - k]:
                    is_good = False
            if i + k < n:
                if nums[i] <= nums[i + k]:
                    is_good = False
            
            if is_good:
                total_sum += nums[i]
        
        return total_sum