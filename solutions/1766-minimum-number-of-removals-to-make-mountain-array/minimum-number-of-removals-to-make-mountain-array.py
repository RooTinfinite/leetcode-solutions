class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        def lisLength(v):
            lis = [v[0]]
            lisLen = [1] * len(v)
            
            for i in range(1, len(v)):
                if v[i] > lis[-1]:
                    lis.append(v[i])
                else:
                    index = bisect.bisect_left(lis, v[i])
                    lis[index] = v[i]
                lisLen[i] = len(lis)
            return lisLen
        
        n = len(nums)
        
        # Get LIS lengths from left to right
        lis = lisLength(nums)
        
        # Get LIS lengths from right to left
        nums.reverse()
        lds = lisLength(nums)
        lds.reverse()
        nums.reverse()
        
        removals = float('inf')
        
        # Check each potential peak
        for i in range(n):
            if lis[i] > 1 and lds[i] > 1:
                removals = min(removals, n + 1 - lis[i] - lds[i])
        
        return removals