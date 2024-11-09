impl Solution {
    pub fn min_end(n: i32, x: i32) -> i64 {
        // Store available bit positions that are 0 in x
        let mut shifts = Vec::new();
        
        // Initialize result with starting number x
        let mut cur = x as i64;
        
        // Calculate how many 1's we need to add (n-1)
        let mut calc = n as i64 - 1;
        
        // Find all bit positions that are 0 in x (up to 32 bits)
        for i in 0..32 {
            if (x & (1 << i)) == 0 {
                shifts.push(i);
            }
        }
        
        // Add remaining positions 32-63 since i64 is 64 bit
        for i in 32..64 {
            shifts.push(i);
        }
        
        // Process each bit in calc (n-1)
        // If bit is 1, set that bit in next available position from shifts
        let mut i = 0;
        while calc > 0 {
            cur += (calc & 1) << shifts[i];
            calc >>= 1;
            i += 1;
        }
        
        cur
    }
}