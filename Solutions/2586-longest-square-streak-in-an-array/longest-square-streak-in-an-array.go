func longestSquareStreak(nums []int) int {
    // Create a map for O(1) lookup time
    numSet := make(map[int]bool)
    
    // Remove duplicates and add to map
    for _, num := range nums {
        numSet[num] = true
    }
    
    // Track the maximum streak length found
    maxLength := 0
    
    // Iterate through each number
    for num := range numSet {
        length := 0
        current := num
        
        // Keep squaring the number while it exists in our map
        for numSet[current] {
            length++
            // Check if squaring would overflow int
            if current > 46340 { // sqrt(MaxInt32) ≈ 46340
                break
            }
            current *= current
        }
        
        // Only update maxLength if we found a streak of length > 1
        if length > 1 {
            maxLength = max(maxLength, length)
        }
    }
    
    // Return maxLength if we found a valid streak, otherwise return -1
    if maxLength > 1 {
        return maxLength
    }
    return -1
}

// Helper function for max
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}