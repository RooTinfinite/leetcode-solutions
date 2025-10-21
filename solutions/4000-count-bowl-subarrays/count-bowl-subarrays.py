class Solution(object):
    def bowlSubarrays(self, nums):
        res = 0
        stk = []
        n = len(nums)

        for i in range(n):
            while stk and nums[stk[-1]] < nums[i]:
                if i - stk[-1] >= 2:
                    res += 1
                stk.pop()
            if stk and i - stk[-1] >= 2:
                res += 1
            stk.append(i)
        return res