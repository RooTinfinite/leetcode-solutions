class Solution(object):
    def rob(self, nums, colors):
        n = len(nums)
        dp0 = 0
        dp1 = nums[0]
        for i in range(1, n):
            if colors[i] == colors[i-1]:
                new1 = dp0 + nums[i]
                new0 = max(dp0, dp1)
            else:
                new0 = max(dp1, dp0)
                new1 = max(dp0, dp1) + nums[i]
            dp0 = new0
            dp1 = new1
        return max(dp0, dp1)