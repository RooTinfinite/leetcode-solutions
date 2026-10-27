class Solution:
    def resilientSubarray(self, nums: list[int], k: int) -> int:
        return max(
            length
            for rem, run in groupby(nums, k.__rmod__)
            for length, summ in enumerate(accumulate(run), 1)
            if not (summ - rem) % k
        )