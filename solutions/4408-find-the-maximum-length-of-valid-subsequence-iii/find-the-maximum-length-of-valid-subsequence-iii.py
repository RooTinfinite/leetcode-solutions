class Solution:
    def maximumLength(self, nums: list[int], k: int) -> int:

        dp = defaultdict(int)
        nums = map(lambda x: x % k, nums)

        for num in nums:
            if num == 0:
                dp[0]+= 1
            else:
                cmpCnt = dp[k - num]
                if cmpCnt >= dp[num]:
                    dp[num] = cmpCnt + 1

        return max(dp.values())