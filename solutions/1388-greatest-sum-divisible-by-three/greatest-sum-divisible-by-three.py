class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        a = [x for x in nums if x % 3 == 0]
        b = sorted([x for x in nums if x % 3 == 1], reverse=True)
        c = sorted([x for x in nums if x % 3 == 2], reverse=True)
        tot, remove = sum(nums), float("inf")

        if tot % 3 == 0:
            remove = 0
        elif tot % 3 == 1:
            if len(b) >= 1:
                remove = min(remove, b[-1])
            if len(c) >= 2:
                remove = min(remove, c[-2] + c[-1])
        else:
            if len(b) >= 2:
                remove = min(remove, b[-2] + b[-1])
            if len(c) >= 1:
                remove = min(remove, c[-1])

        return tot - remove