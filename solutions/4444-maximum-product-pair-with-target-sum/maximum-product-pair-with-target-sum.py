class Solution:
    def maxProductPair(self, nums: list[int], target: int) -> list[int]:
        ans, best, seen = [-1, -1], -inf, {}  # seen: value -> an index holding it
        for i, x in enumerate(nums):
            if (y := target - x) != x and y in seen and x * y > best:  # a better pair whose partner came earlier
                best, ans = x * y, ([i, seen[y]] if x > y else [seen[y], i])  # larger value first
            seen[x] = i
        return ans