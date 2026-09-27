class Solution:
    def longestSubarray(self, nums: list[int], k: int) -> int:
        n, best = len(nums), 0
        for l in range(n):
            if n - l <= best:
                break
            total, doubled = 0, set()
            for r in range(l, n):
                total += nums[r]
                doubled.add(2 * nums[r] % k)
                if total % k == 0 or total % k in doubled:
                    best = max(best, r - l + 1)
        return best