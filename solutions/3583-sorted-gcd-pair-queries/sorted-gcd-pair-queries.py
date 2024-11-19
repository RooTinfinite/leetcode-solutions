from itertools import accumulate
from bisect import bisect_right
from typing import List

class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        maxv = max(nums)
        co = [0] * (maxv + 1)
        lcount = [0] * (maxv + 1)
        
        # Count the occurrence of each number in nums
        for v in nums:
            co[v] += 1
        
        # Calculate lcount for each divisor
        for i in range(1, maxv + 1):
            x = 0
            for mul in range(i, maxv + 1, i):
                x += co[mul]
            lcount[i] = x * (x - 1) // 2
        
        # Adjust lcount to subtract over-counted GCDs
        for i in range(maxv, 0, -1):
            for mul in range(2 * i, maxv + 1, i):
                lcount[i] -= lcount[mul]
        
        # Accumulate counts for answering queries efficiently
        acc = list(accumulate(lcount))
        
        # Answer each query by finding the appropriate GCD count using binary search
        return [bisect_right(acc, q) for q in queries]