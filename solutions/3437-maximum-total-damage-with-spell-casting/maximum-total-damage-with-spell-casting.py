class Solution:
    def maximumTotalDamage(self, nums: List[int]) -> int:
        nums.sort()
        dp = []
        preMax = 0
        ans = 0
        dpIdx = 0

        i = 0
        while i < len(nums):
            while dpIdx < len(dp) and dp[dpIdx][0] + 2 < nums[i]:
                preMax = max(preMax, dp[dpIdx][1])
                dpIdx += 1

            j = i
            cur = 0
            while j < len(nums) and nums[j] == nums[i]:
                cur += nums[j]
                j += 1

            ans = max(ans, cur + preMax)
            dp.append((nums[i], cur + preMax))
            i = j

        return ans