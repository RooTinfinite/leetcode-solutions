class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        # Sort array to group equal elements together
        nums.sort()
        # Check consecutive pairs in sorted array
        return all(nums[i] == nums[i + 1] for i in range(0, len(nums), 2))