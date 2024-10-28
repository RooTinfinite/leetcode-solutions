class Solution {
    func longestSquareStreak(_ nums: [Int]) -> Int {
        // Convert nums to a sorted set to remove duplicates and have ordered numbers
        let sortedNums = Array(Set(nums)).sorted()
        
        // Create a set for O(1) lookup time
        let numSet = Set(nums)
        
        // Track the maximum streak length found
        var maxLength = 0
        
        // Iterate through each number in sorted order
        for num in sortedNums {
            // Initialize streak length for current number
            var length = 0
            // Start with current number
            var current = num
            
            // Keep squaring the number while it exists in our set
            while numSet.contains(current) {
                length += 1
                // Need to handle potential integer overflow
                let nextSquare = current * current
                if nextSquare > Int.max {
                    break
                }
                current = nextSquare
            }
            
            // Only update maxLength if we found a streak of length > 1
            if length > 1 {
                maxLength = max(maxLength, length)
            }
        }
        
        // Return maxLength if we found a valid streak, otherwise return -1
        return maxLength > 1 ? maxLength : -1
    }
}