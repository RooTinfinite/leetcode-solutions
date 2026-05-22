class Solution:
    def minimumK(self, nums: List[int]) -> int:
        # Filter <= 0
        nums = [num for num in nums if num > 0]
        if len(nums) == 0:
            return 0

        def nonPositive(k):
            return sum(math.ceil(num / k) for num in nums)

        l, r = 1, max(max(nums), len(nums))
        while l < r:
            m = l + (r - l) // 2
            if nonPositive(m) <= m * m:
                r = m
            else:
                l = m + 1

        return l