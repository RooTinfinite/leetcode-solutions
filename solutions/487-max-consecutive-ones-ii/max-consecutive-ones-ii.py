class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        
        without_flip, with_flip = 0, 0
        max_ones = 0
        for num in nums:
            if num == 1:
                without_flip += 1
                with_flip += 1
            else:
                with_flip = without_flip+1
                without_flip = 0
            max_ones = max(max_ones, with_flip)
        
        return max_ones