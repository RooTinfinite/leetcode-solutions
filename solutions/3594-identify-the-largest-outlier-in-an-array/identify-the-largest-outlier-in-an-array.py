class Solution:
    def getLargestOutlier(self, nums: List[int]) -> int:

        ctr, sm = Counter(nums), sum(nums)
        cands = sorted(ctr, reverse = True)

        for n in cands:
            d, m = divmod(sm - n, 2)
            if m: continue
                
            if d in cands and (d != n or ctr[d] > 1): return n