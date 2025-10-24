class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        one, two = 0, costs[0] + 1
        three = costs[1] + min(two + 1, 4) if n > 1 else two
        for i in range(3, n + 1):
            curr = costs[i-1] + min([three + 1, two + 4, one + 9])
            one, two, three = two, three, curr
        return three