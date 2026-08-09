from collections import deque
from typing import List

class Solution:
    def sortArray(self, nums: List[int], pre: List[int]) -> int:
        start = tuple(nums)
        target = tuple(sorted(nums))
        
        if start == target:
            return 0
            
        queue = deque([start])
        visited = set([start])
        res = 0
        
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                
                for p in pre:
                    # Slice and reverse the prefix, then append the rest
                    next_state = curr[:p][::-1] + curr[p:]
                    
                    if next_state == target:
                        return res + 1
                        
                    if next_state not in visited:
                        visited.add(next_state)
                        queue.append(next_state)
                        
            res += 1
            
        return -1