class Solution:
    def goodIndices(self, nums: List[int], k: int) -> List[int]:
        def noninc_subarr_len(lis):
            l = [lis[i] <= lis[i-1] for i in range(1, len(lis))]
            res = [0, 1]
            for is_non_increasing in l[:-1]:
                res.append(res[-1] * is_non_increasing + 1)
            return res
        before, after = noninc_subarr_len(nums), noninc_subarr_len(nums[::-1])
        return [idx for idx in range(len(nums)) if min(before[idx], after[-1-idx]) >= k]