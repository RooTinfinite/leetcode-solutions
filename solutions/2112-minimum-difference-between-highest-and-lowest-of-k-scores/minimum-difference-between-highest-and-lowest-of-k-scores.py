class Solution:
    def minimumDifference(self, nums: list[int], k: int) -> int:
        if (nums == [] or k <= 1 or len(nums) < k):
            return 0
        nums.sort()
        lowest = float('inf')
        for i in range(len(nums) - k + 1):
            diff = nums[i + k - 1] - nums[i]
            if diff < lowest:
                lowest = diff
        return lowest