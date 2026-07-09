class Solution:
    def firstStableIndex(self, nums, k):
        n = len(nums)
        prefixMax = [0] * n
        suffixMin = [10**9] * n
        prefixMax[0] = nums[0]
        suffixMin[n - 1] = nums[n - 1]
        for i in range(1, n):
            prefixMax[i] = max(prefixMax[i - 1], nums[i])
            suffixMin[n - 1 - i] = min(suffixMin[n - i], nums[n - 1 - i])
        for i in range(n):
            if prefixMax[i] - suffixMin[i] <= k:
                return i
        return -1