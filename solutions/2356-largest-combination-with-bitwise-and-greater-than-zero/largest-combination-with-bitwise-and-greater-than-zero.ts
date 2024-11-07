function largestCombination(candidates: number[]): number {
    // Create array to store count of 1's at each bit position (32 bits for integers)
    const ans: number[] = new Array(32).fill(0);
    
    // Iterate through each number in candidates array
    for (const x of candidates) {
        // Count the number of 1's at each bit position for current number
        find(x, ans);
    }
    
    // Find the maximum count of 1's across all bit positions
    let res = 0;
    for (let i = 0; i < 32; i++) {
        res = Math.max(res, ans[i]);
    }
    
    // Return the largest possible combination
    return res;
}

// Helper function to count number of 1's at each bit position
function find(n: number, ans: number[]): void {
    // Start from rightmost bit (31st position)
    let j = 31;
    
    // Continue until all bits are processed
    while (n > 0) {
        // Get the rightmost bit using bitwise AND with 1
        const a = n & 1;
        
        // Add the bit count to corresponding position in ans array
        ans[j] += a;
        
        // Right shift n by 1 to process next bit
        n >>= 1;
        
        // Move to next bit position from right to left
        j--;
    }
}