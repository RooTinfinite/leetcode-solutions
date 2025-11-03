class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        mn = nums[0]
        mx = nums[0]

        for num in nums:
            mn = min(mn, num)
            mx = max(mx, num)

        seen = set(nums)
        res = []

        for i in range(mn, mx + 1):
            if i not in seen:
                res.append(i)

        return res