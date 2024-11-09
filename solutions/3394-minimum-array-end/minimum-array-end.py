class Solution:
    def minEnd(self, n: int, x: int) -> int:
        result = x
        remaining = n - 1
        position = 0
        
        while remaining:
            current_bit = 1 << position
            if not (x & current_bit):
                result |= (remaining & 1) << position
                remaining >>= 1
            position += 1
            
        return result