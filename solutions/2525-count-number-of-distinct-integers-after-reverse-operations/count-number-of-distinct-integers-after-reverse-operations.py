class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        original=len(nums)
        for i in range(original):
            nums.append(int(str(nums[i])[::-1]))
        return len(set(nums))
        