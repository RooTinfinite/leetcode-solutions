class Solution:
    def minChanges(self, n: int, k: int) -> int:
        if n == k:
            return 0
        
        count = 0
        while n > 0 or k > 0:
            bitN = n & 1
            bitK = k & 1
            
            if bitK == 1 and bitN == 0:
                return -1
            
            if bitN == 1 and bitK == 0:
                count += 1
                
            n >>= 1
            k >>= 1
        
        return count