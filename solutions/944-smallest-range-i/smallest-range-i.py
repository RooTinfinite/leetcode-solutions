class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        l=s=nums[0]
        for i in nums:
            if l<i:
                l=i
            if s>i:
                s=i

        return max(0,l-s-2*k)