class Solution {
    // Determines if an array can be sorted by swapping adjacent elements with same number of set bits
    func canSortArray(_ nums: [Int]) -> Bool {
        let n = nums.count
        
        // Create a copy of input array to work with
        var values = nums
        
        // Forward pass - check and swap from left to right
        for i in 0..<(n-1) {
            // Skip if elements are already in order
            if values[i] <= values[i + 1] { continue }
            else {
                // Check if adjacent elements have same number of set bits
                if values[i].nonzeroBitCount == values[i + 1].nonzeroBitCount {
                    // Swap elements if they have same number of set bits
                    values.swapAt(i, i + 1)
                } 
                else { return false } // Cannot swap elements with different number of set bits
            }
        }
        
        // Backward pass - check and swap from right to left
        for i in stride(from: n-1, through: 1, by: -1) {
            // Skip if elements are already in order
            if values[i] >= values[i - 1] { continue }
            else {
                // Check if adjacent elements have same number of set bits
                if values[i].nonzeroBitCount == values[i - 1].nonzeroBitCount {
                    // Swap elements if they have same number of set bits
                    values.swapAt(i, i - 1)
                } 
                else { return false } // Cannot swap elements with different number of set bits
            }
        }
        
        // Array can be sorted if we reach here
        return true
    }
}