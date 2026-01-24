class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()

        n = len(nums)
        min_max_sum = 0

        for i in range(n // 2):
            min_max_sum = max(min_max_sum, nums[i] + nums[n - 1 - i])

        return min_max_sum        