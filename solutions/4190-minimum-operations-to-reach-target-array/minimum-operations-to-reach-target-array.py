class Solution:
    def minOperations(self, nums: List[int], target: List[int]) -> int:
        s = set()

        for i in range(len(nums)):
            if nums[i] != target[i]:
                s.add(nums[i])

        return len(s)
