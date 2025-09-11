class Solution:
    def xorAfterQueries(self, nums: List[int], q: List[List[int]]) -> int:
        mod = 10**9 + 7
        for l, r, k, v in q:
            while l <= r:
                nums[l] = (nums[l] * v) % mod
                l += k
        ans = 0
        for num in nums:
            ans ^= num
        return ans