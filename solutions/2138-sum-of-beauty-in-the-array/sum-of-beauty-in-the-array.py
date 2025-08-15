class Solution:
    def sumOfBeauties(self, nums):
        n = len(nums)
        pref = [0] * n
        suf = [0] * n

        pref[0] = nums[0]
        for i in range(1, n - 1):
            pref[i] = max(pref[i - 1], nums[i])

        suf[n - 1] = nums[n - 1]
        for i in range(n - 2, 0, -1):
            suf[i] = min(suf[i + 1], nums[i])

        res = 0
        for i in range(1, n - 1):
            if nums[i] > pref[i - 1] and nums[i] < suf[i + 1]:
                res += 2
            elif nums[i] > nums[i - 1] and nums[i] < nums[i + 1]:
                res += 1
        return res