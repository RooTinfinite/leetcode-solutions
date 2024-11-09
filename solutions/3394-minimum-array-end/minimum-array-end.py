class Solution:
    def minEnd(self, n: int, x: int) -> int:
        # Store positions where bits are 0 in x
        shifts = []
        cur = x
        # Calculate how many steps needed (n-1)
        calc = n - 1
        
        # Find positions of 0 bits in x (first 32 bits)
        for i in range(32):
            if not ((1 << i) & x):
                shifts.append(i)
        
        # Add positions 32-63 as potential shift positions
        for i in range(32, 64):
            shifts.append(i)
        
        # Process each bit in calc (n-1)
        i = 0
        while calc > 0:
            # If current bit in calc is 1, set that bit in cur
            # using the next available shift position
            cur += (calc & 1) << shifts[i]
            # Right shift calc to process next bit
            calc >>= 1
            # Move to next available shift position
            i += 1
            
        return cur