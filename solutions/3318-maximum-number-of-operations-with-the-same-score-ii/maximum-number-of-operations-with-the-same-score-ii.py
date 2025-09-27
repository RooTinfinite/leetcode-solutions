class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        def func(l, r, nums, num):
            if l >= r:
                return 0
            if dp[l][r] != -1:
                return dp[l][r]

            ans = 0
            if nums[l] + nums[l + 1] == num:
                ans = max(ans, 1 + func(l + 2, r, nums, num))
            if nums[r] + nums[r - 1] == num:
                ans = max(ans, 1 + func(l, r - 2, nums, num))
            if nums[l] + nums[r] == num:
                ans = max(ans, 1 + func(l + 1, r - 1, nums, num))

            dp[l][r] = ans
            return ans

        n = len(nums)
        dp = [[-1] * n for _ in range(n)]

        ans = 0
        ans = max(ans, 1 + func(2, n - 1, nums, nums[0] + nums[1]))
        ans = max(ans, 1 + func(0, n - 3, nums, nums[-1] + nums[-2]))
        ans = max(ans, 1 + func(1, n - 2, nums, nums[0] + nums[-1]))

        return ans