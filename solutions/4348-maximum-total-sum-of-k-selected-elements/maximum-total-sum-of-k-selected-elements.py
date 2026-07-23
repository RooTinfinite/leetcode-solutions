class Solution:
    def maxSum(self, nums, k, mul):
        nums.sort()

        i = len(nums) - 1
        ans = 0

        while k:
            if mul > 0:
                ans += nums[i] * mul
            else:
                ans += nums[i]

            i -= 1
            k -= 1
            mul -= 1

        return ans