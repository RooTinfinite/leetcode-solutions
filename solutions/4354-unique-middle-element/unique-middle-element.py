class Solution:
    def isMiddleElementUnique(self, nums: List[int]) -> bool:
        target = len(nums) // 2
        count = 0

        for num in nums:
            if num == nums[target]:
                count += 1

            if count > 1:
                return False

        return True