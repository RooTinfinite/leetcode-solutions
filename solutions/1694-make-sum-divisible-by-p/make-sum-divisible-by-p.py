class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        
        target = sum(nums) % p

        if target == 0:
            return 0
        
        presum = {0 : -1}
        total = 0
        res = len(nums)
        for i in range(len(nums)):
            total += nums[i]
            mod = (total - target) % p
            if mod in presum:
                res = min(res, i - presum[mod])
            presum[total%p] = i 
        
        return res if res != len(nums) else -1