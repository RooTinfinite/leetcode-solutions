class Solution:
    def minOperations(self, nums: list[int], locked: list[int], k: int) -> int:
        unlock = inversions= 0
        seen = []
        for i, num in enumerate(nums):
            j = bisect_left(seen, num)
            seen.insert(j, num)
            inversions += i - j
            if locked[i] and (num != i+1 or j != i):
                unlock += 1
        return unlock + inversions if unlock <= k else -1