class Solution {
    func minEnd(_ n: Int, _ x: Int) -> Int {
        // Store available bit positions that are 0 in x
        var shifts: [Int] = []
        
        // Initialize result with starting number x
        var cur = x
        
        // Calculate how many 1's we need to add (n-1)
        var calc = n - 1
        
        // Find all bit positions that are 0 in x (up to 32 bits)
        for i in 0..<32 {
            if ((1 << i) & x) == 0 {
                shifts.append(i)
            }
        }
        
        // Add remaining positions 32-63 since Int64 is 64 bit
        for i in 32..<64 {
            shifts.append(i)
        }
        
        // Process each bit in calc (n-1)
        // If bit is 1, set that bit in next available position from shifts
        var i = 0
        while calc > 0 {
            cur += ((calc & 1) << shifts[i])
            i += 1
            calc >>= 1
        }
        
        return cur
    }
}