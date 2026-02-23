from fractions import Fraction 

class Solution:
    def countSequences(self, nums: List[int], k: int) -> int:
        dp = Counter({Fraction(1, 1): 1})
        for num in nums:
            newdp = Counter()
            for val, cnt in dp.items():
                newdp[val]       += cnt
                newdp[val * num] += cnt
                newdp[val / num] += cnt
            dp = newdp
        return dp[Fraction(k, 1)]