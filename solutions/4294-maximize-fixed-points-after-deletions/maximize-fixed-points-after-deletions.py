class Solution:
    def maxFixedPoints(self, nums: list[int]) -> int:
        n = len(nums)
        v = []

        # store (i - nums[i], nums[i])
        for i in range(n):
            if nums[i] <= i:
                v.append((i - nums[i], nums[i]))

        if not v:
            return 0

        # sort by d, then by value
        v.sort()

        # LIS on values
        lis = []

        for d, val in v:
            idx = bisect_left(lis, val)

            if idx == len(lis):
                lis.append(val)
            else:
                lis[idx] = val

        return len(lis)