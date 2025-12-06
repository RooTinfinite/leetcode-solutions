class Solution:
    def minInversionCount(self, nums: List[int], k: int) -> int:
        res = float("inf")
        sl = SortedList()
        cnt, j = 0, 0

        for i, v in enumerate(nums):
            if len(sl) == k:
                a = sl.bisect_left(nums[j])
                cnt -= a
                sl.discard(nums[j])
                j += 1
            
            b = sl.bisect_right(v)
            cnt += len(sl) - b
            sl.add(v)

            if len(sl) == k:
                res = min(res, cnt)

        return res