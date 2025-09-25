class Solution:
  def minimumSum(self, nums: List[int]) -> int:

    pref = list(accumulate(nums, func = min))
    suff = list(accumulate(nums[::-1], func = min))[-3::-1]

    return min((p + n + s for p, n, s in zip(pref, nums[1:-1], suff)
                                 if (p < n and n > s)), default= -1)