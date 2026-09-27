from collections import Counter

class Solution:
    def rearrangeArray(self, nums: list[int]) -> list[int]:
        counts = Counter(nums)
        max_freq = max(counts.values()) if counts else 0
        sorted_unique = sorted(counts.keys())
        
        ans = []
        for _ in range(max_freq):
            for val in sorted_unique:
                if counts[val] > 0:
                    ans.append(val)
                    counts[val] -= 1
                    
        return ans