from collections import defaultdict

class Solution:
    def maxEqualAdjacentPairs(self, nums: list[int]) -> int:
        n = len(nums)
        base_pairs = 0
        pair_count = defaultdict(int)
        max_new_pairs = 0

        for i in range(n - 1):
            if nums[i] == nums[i + 1]:
                base_pairs += 1
            else:
                u = min(nums[i], nums[i + 1])
                v = max(nums[i], nums[i + 1])
                pair_count[(u, v)] += 1
                if pair_count[(u, v)] > max_new_pairs:
                    max_new_pairs = pair_count[(u, v)]

        return base_pairs + max_new_pairs