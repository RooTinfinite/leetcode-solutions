class Solution:
    def findMaxVal(self, n, restrictions, diff):
        INF = 10**18
        
        # Initialize limits
        limit = [INF] * n
        limit[0] = 0
        
        for idx, maxVal in restrictions:
            limit[idx] = maxVal
        
        # Forward pass
        for i in range(1, n):
            limit[i] = min(limit[i], limit[i-1] + diff[i-1])
        
        # Backward pass
        for i in range(n-2, -1, -1):
            limit[i] = min(limit[i], limit[i+1] + diff[i])
        
        return max(limit)