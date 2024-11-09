class Solution:
    def minEnd(self, n: int, x: int) -> int:
        shifts = []
        cur = x
        calc = n - 1
        
        for i in range(32):
            if not ((1 << i) & x):
                shifts.append(i)
        
        for i in range(32, 64):
            shifts.append(i)
        
        i = 0
        while calc > 0:
            cur += (calc & 1) << shifts[i]
            calc >>= 1
            i += 1
            
        return cur