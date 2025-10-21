class Solution:
    def smallestAbsent(self, nums: List[int]) -> int:
        avg = sum(nums) / len(nums)
        count = 1
        while True:
            if count > avg and count not in nums:
                return count
            else:
                count += 1