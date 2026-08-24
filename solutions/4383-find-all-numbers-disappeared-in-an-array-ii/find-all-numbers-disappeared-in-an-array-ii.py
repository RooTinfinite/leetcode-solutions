class Solution:
    def findDisappearedNumbers(self, nums, lower, upper):
        nums.sort()
        res = []
        cur = lower

        for num in nums:
            if num < lower or num > upper:
                continue

            if cur < num:
                res.append([cur, num - 1])
            cur = max(cur, num + 1)

            if cur > upper:
                break

        if cur <= upper:
            res.append([cur, upper])

        return res