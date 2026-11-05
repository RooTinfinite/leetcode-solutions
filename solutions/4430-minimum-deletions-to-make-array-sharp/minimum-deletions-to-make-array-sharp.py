class Solution:
    def minDeletions(self, nums: list[int]) -> int:

        ans = 0
        
        for lft, rgt in pairwise(nums):
            if lft == rgt:
                ans+= 1

        return ans