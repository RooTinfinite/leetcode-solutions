class Solution:
    def minCost(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        length = len(queries)

        pre = [0] * n
        suff = [0] * n

        for i in range(n - 1):
            diffFromRight = nums[i + 1] - nums[i]
            diffFromLeft = nums[i] - nums[i - 1] if i > 0 else float('inf')

            pre[i + 1] = pre[i] + (1 if diffFromRight < diffFromLeft else diffFromRight)

        for i in range(n - 1, 0, -1):
            diffFromLeft = nums[i] - nums[i - 1]
            diffFromRight = nums[i + 1] - nums[i] if i < n - 1 else float('inf')

            suff[i - 1] = suff[i] + (1 if diffFromLeft <= diffFromRight else diffFromLeft)

        ans = [0] * length

        for i in range(length):
            l = queries[i][0]
            r = queries[i][1]

            if l <= r:
                ans[i] = pre[r] - pre[l]
            else:
                ans[i] = suff[r] - suff[l]

        return ans