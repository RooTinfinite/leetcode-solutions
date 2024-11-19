class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        @cache
        def dfs(i, a, b):
            if i == len(nums):
                return 1 if a == b else 0
            return (
                dfs(i + 1, a, b) +  # do not take 
                dfs(i + 1, gcd(a, nums[i]), b) +  # take into A
                dfs(i + 1, a, gcd(b, nums[i]))  # take into B
            ) % (10 ** 9 + 7)
        return dfs(0, 0, 0) - 1  # exclude the one case to take nothing