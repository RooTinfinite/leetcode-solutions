class Solution:
    def centeredSubarrays(self, nums: List[int]) -> int:
        result = 0
        n = len(nums)
        for start in range(n):
            running_sum = 0
            elements_set = set()
            for end in range(start, n):
                running_sum += nums[end]
                elements_set.add(nums[end])
                if running_sum in elements_set:
                    result += 1
        return result