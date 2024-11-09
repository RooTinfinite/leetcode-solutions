class Solution:
 #Function to find minimum ending number given n and starting number x
    def minEnd(self, n: int, x: int) -> int:
        # Store available bit positions that are 0 in x
        shifts = []
        
        # Initialize result with starting number x
        cur = x
        
        # Calculate how many 1's we need to add (n-1)
        calc = n - 1
        
        # Find all bit positions that are 0 in x (up to 32 bits)
        for i in range(32):
            if not ((1 << i) & x):
                shifts.append(i)
        
        # Add remaining positions 32-63 since long long is 64 bit
        for i in range(32, 64):
            shifts.append(i)
        
        # Process each bit in calc (n-1)
        i = 0
        while calc > 0:
            # If bit is 1, set that bit in next available position from shifts
            # using positions from shifts array
            cur += (calc & 1) << shifts[i]
            
            # Right shift calc to process next bit
            calc >>= 1
            
            # Move to next available position in shifts
            i += 1
        # Return the final constructed number
        return cur