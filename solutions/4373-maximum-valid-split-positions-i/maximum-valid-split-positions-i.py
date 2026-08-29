from math import gcd

class Solution:
    def maxValidSplits(self, nums):
        n = len(nums)
        ans = 0

        for i in range(-1, n):

            arr = [nums[j] for j in range(n) if j != i]

            m = len(arr)

            if m < 2:
                continue

            prefix = [0] * m
            suffix = [0] * m

            prefix[0] = arr[0]

            for j in range(1, m):
                prefix[j] = gcd(prefix[j - 1], arr[j])

            suffix[m - 1] = arr[m - 1]

            for j in range(m - 2, -1, -1):
                suffix[j] = gcd(suffix[j + 1], arr[j])

            score = 0

            for j in range(m - 1):
                if prefix[j] == suffix[j + 1]:
                    score += 1

            ans = max(ans, score)

        return ans