class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        
        def countPairs(target):
            left, right = 0, len(nums) - 1
            count = 0
            
            while left < right:
                curr_sum = nums[left] + nums[right]
                if curr_sum <= target:
                    count += right - left
                    left += 1
                else:
                    right -= 1
            return count
        
        return countPairs(upper) - countPairs(lower - 1)