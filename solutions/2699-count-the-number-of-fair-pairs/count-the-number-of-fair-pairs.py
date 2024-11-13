class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        
        def countPairsLessEqual(target):
            left, right = 0, len(nums) - 1
            total = 0
            while left < right:
                if nums[left] + nums[right] <= target:
                    total += right - left
                    left += 1
                else:
                    right -= 1
            return total
        
        return countPairsLessEqual(upper) - countPairsLessEqual(lower - 1)