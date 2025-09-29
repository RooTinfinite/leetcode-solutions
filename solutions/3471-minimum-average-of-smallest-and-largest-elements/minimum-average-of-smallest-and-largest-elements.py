class Solution:
    def minimumAverage(self, nums: list[int]) -> float:
        nums.sort()
        left, right = 0, len(nums) - 1
        min_avg = float('inf')

        while left < right:
            avg = (nums[left] + nums[right]) / 2
            min_avg = min(min_avg, avg)
            left += 1
            right -= 1
        return min_avg