class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        l, r =0, 0
        mx, total = 0, 0
        visit = set()
        while r<len(nums):
            while nums[r] in visit:
                total -= nums[l]
                visit.remove(nums[l])
                l+=1
            total += nums[r]
            visit.add(nums[r])
            if (r-l+1) == k:
                mx = max(mx, total)
                total -= nums[l]
                visit.remove(nums[l])
                l+=1
            
            r+=1
        return mx
            