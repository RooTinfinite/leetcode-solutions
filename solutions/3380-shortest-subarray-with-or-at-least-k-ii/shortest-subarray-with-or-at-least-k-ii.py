class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = inf
        d = dict() 
        for i, x in enumerate(nums):
            d = {or_ | x: left for or_, left in d.items()}
            d[x] = i  
            for or_, left in d.items():
                if or_ >= k:
                    ans = min(ans, i - left + 1)
        return ans if ans < inf else -1