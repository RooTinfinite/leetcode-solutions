class Solution:
    def subarraySum(self, nums: List[int]) -> int:
        pref = [0] * (len(nums) + 1)
        for i in range(1, len(nums) + 1):
            pref[i] += pref[i-1] + nums[i-1]

        res = 0
        for i in range(len(nums)):
            start = max(0, i - nums[i])
            res += pref[i+1] - pref[start]

        return res