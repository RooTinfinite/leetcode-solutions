mod = 1_000_000_007

class Solution:
    def alternatingXOR(self, nums: List[int], 
                             target1: int, target2: int) -> int:

        dp1, dp2 = defaultdict(int), defaultdict(int)
        dp1[0]=1

        for num, xorPref in zip(nums, accumulate(nums, xor)):

            xorCnt1 = dp1[xorPref ^ target1] %mod
            xorCnt2 = dp2[xorPref ^ target2] %mod
            dp2[xorPref]+= xorCnt1
            dp1[xorPref]+= xorCnt2

        return (xorCnt1 + xorCnt2) %mod