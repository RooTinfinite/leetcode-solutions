class Solution:
    def minEnd(self, n: int, x: int) -> int:
        result = x
        n -= 1
        pos = 0
        
        while n:
            if not (x & (1 << pos)):
                result |= (n & 1) << pos
                n >>= 1
            pos += 1
            
        return result