class Solution:
    def maxAlternatingSum(self, nums: list[int]) -> int:
        ans = plus = minus = plus_del = minus_del = -inf
        for x in nums:
            plus, minus, plus_del, minus_del = (
                max(x, minus + x),  # start fresh at x, or add x after a minus
                plus - x,  # subtract x after a plus
                max(minus_del + x, plus),  # add x after a minus with deletion used, or delete x
                max(plus_del - x, minus),  # subtract x after a plus with deletion used, or delete x
            )
            ans = max(ans, plus, minus, plus_del, minus_del)
        return ans