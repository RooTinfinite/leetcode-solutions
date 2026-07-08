class Solution:
    def minIncrease(self, nums):
        n = len(nums)

        # Odd length: fixed pattern
        if n % 2 == 1:
            ans = 0
            for i in range(1, n - 1, 2):
                ans += max(0, max(nums[i - 1], nums[i + 1]) + 1 - nums[i])
            return ans

        @lru_cache(None)
        def r(pos, skip):
            if pos >= n - 1:
                return 0

            cost = max(0, max(nums[pos - 1], nums[pos + 1]) + 1 - nums[pos])

            if skip:
                return cost + r(pos + 2, True)

            return min(
                cost + r(pos + 2, False),
                cost + r(pos + 3, True)
            )

        return min(
            r(1, False),
            r(2, True)
        )