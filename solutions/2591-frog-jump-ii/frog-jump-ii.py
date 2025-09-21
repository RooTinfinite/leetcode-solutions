class Solution:
    def maxJump(self, stones: List[int]) -> int:
        if len(stones) == 2:
            return (stones[-1] - stones[0])
        maxjump = 0
        i, j = 0, 2
        while j < len(stones):
            maxjump = max(maxjump, (stones[j] - stones[i]))
            i+= 1; j+= 1
        return maxjump
        