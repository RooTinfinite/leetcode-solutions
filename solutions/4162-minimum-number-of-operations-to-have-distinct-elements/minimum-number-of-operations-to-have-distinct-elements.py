class Solution:
    def minOperations(self, nums: List[int]) -> int:
       
        seen = {nums.pop()}

        while nums:
            if nums[-1] in seen:
                return (len(nums) + 2) // 3
            seen.add(nums.pop())

        return 0
            