class Solution:
    def findValidElements(self, nums):
        n = len(nums)
        prefix = [False] * n
        prefix[0] = True
        prefix[n-1] = True
        
        maxEle = nums[0]
        for i in range(1, n-1):
            if nums[i] > maxEle:
                maxEle = nums[i]
                prefix[i] = True
        
        maxEle = nums[n-1]
        for i in range(n-2, 0, -1):
            if nums[i] > maxEle:
                maxEle = nums[i]
                prefix[i] = True
        
        ans = [nums[i] for i in range(n) if prefix[i]]
        return ans