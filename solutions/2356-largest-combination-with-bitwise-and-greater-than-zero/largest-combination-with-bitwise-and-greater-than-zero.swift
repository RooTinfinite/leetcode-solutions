class Solution {
    // This method finds the largest combination of numbers from the candidates array
    // that have at least one common set bit (1) in their binary representation
    func largestCombination(_ candidates: [Int]) -> Int {
        // Create array to store count of 1's at each bit position (32 bits for integers)
        var ans = Array(repeating: 0, count: 32)
        
        // Iterate through each number in candidates array
        for x in candidates {
            // Count the number of 1's at each bit position for current number
            find(x, &ans)
        }
        
        // Find the maximum count of 1's across all bit positions
        return ans.max() ?? 0
    }
    
    // Helper method to count number of 1's at each bit position
    func find(_ n: Int, _ ans: inout [Int]) {
        // Start from rightmost bit (31st position)
        var j = 31
        var num = n
        
        // Continue until all bits are processed
        while num > 0 {
            // Get the rightmost bit using bitwise AND with 1
            let a = num & 1
            
            // Add the bit count to corresponding position in ans array
            ans[j] += a
            
            // Right shift n by 1 to process next bit
            num >>= 1
            
            // Move to next bit position from right to left
            j -= 1
        }
    }
}