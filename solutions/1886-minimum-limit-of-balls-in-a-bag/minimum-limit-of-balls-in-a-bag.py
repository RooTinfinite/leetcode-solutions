class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        def can_divide(penalty):
            operations = sum((x - 1) // penalty for x in nums)
            return operations <= maxOperations
        
        left = 1
        right = max(nums)
        
        while left < right:
            mid = (left + right) // 2
            if can_divide(mid):
                right = mid
            else:
                left = mid + 1
                
        return left
