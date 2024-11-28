class Solution(object):
    def numSubarrayBoundedMax(self, A, L, R):
        """
        :type A: List[int]
        :type L: int
        :type R: int
        :rtype: int
        """
        # using Sliding window
        windowStart = count = curr = 0
        
        for windowEnd, num in enumerate(A):
            
            if L <= num <= R:
                curr = windowEnd - windowStart + 1
            elif num > R:
                curr = 0
                windowStart = windowEnd + 1
            
            count += curr
        
        return count
            