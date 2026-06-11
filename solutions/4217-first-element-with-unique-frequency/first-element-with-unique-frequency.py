from typing import List
from collections import defaultdict

class Solution:
    def firstUniqueFreq(self, nums: List[int]) -> int:
        if not nums:
            return -1
        
        counter = defaultdict(int)
        for num in nums:
            counter[num] += 1
        
        freq = defaultdict(int)
        for count in counter.values():
            freq[count] += 1
        
        for num in nums:
            count = counter[num]
            if freq[count] == 1:
                return num
        
        return -1