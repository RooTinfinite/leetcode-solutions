public class Solution {
    public long MinEnd(int n, int x) {
        // Store available bit positions that are 0 in x
        List<int> shifts = new List<int>();
        
        // Initialize result with starting number x
        long cur = x;
        
        // Calculate how many 1's we need to add (n-1)
        long calc = n - 1;
        
        // Find all bit positions that are 0 in x (up to 32 bits)
        for(int i = 0; i < 32; i++) {
            if((x & (1 << i)) == 0) {
                shifts.Add(i);
            }
        }
        
        // Add remaining positions 32-63 since long is 64 bit
        for(int i = 32; i < 64; i++) {
            shifts.Add(i);
        }
        
        // Process each bit in calc (n-1)
        // If bit is 1, set that bit in next available position from shifts
        for(int i = 0; calc > 0; i++, calc >>= 1) {
            cur += (calc & 1L) << shifts[i];
        }
        
        return cur;
    }
}