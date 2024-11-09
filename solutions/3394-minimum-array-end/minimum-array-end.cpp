class Solution {
public:
 // Function to find minimum ending number given n and starting number x
    long long minEnd(int n, int x) {
        // Store available bit positions that are 0 in x
        vector<short> shifts;
        
        // Initialize result with starting number x
        long long cur = x;
        
        // Calculate how many 1's we need to add (n-1)
        long long calc = n - 1;
        
        // Find all bit positions that are 0 in x (up to 32 bits)
        for(int i = 0; i < 32; i++) 
            if(!((1 << i) & x))
                shifts.push_back(i);
        
        // Add remaining positions 32-63 since long long is 64 bit
        for(int i = 32; i < 64; i++)
            shifts.push_back(i);
        
        // Process each bit in calc (n-1)
        // If bit is 1, set that bit in next available position from shifts
        for(int i = 0; calc > 0; i++, calc >>= 1) {
            cur += (calc & 1) << shifts[i];
        }
        
        // Return the final constructed number
        return cur;
    }
};