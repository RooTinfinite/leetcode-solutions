class Solution:
    def maxSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        l = 0
        count = [0] * 501
        
        def is_valid(target: int) -> bool:
            for i in range(1, target // 2 + 1):
                if i == target - i:
                    if count[i] >= 2:
                        return False
                else:
                    if count[i] > 0 and count[target - i] > 0:
                        return False
                        
            for i in range(1, 501 - target):
                if count[i] > 0 and count[i + target] > 0:
                    return False
                    
            return True
            
        for r in range(n):
            while not is_valid(nums[r]):
                count[nums[l]] -= 1
                l += 1
                
            count[nums[r]] += 1
            ans = max(ans, r - l + 1)
            
        return ans