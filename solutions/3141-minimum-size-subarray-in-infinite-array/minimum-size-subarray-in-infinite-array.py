class Solution:
    def minSizeSubarray(self, nums: List[int], target: int) -> int:
        q, target = divmod(target, sum(nums))
        ans = q*len(nums)
        cand = inf 
        ii = 0 
        for i, x in enumerate(nums + nums): 
            target -= x
            while target < 0: 
                target += nums[ii % len(nums)]
                ii += 1
            if target == 0: cand = min(cand, i-ii+1)
        return ans + cand if cand < inf else -1 