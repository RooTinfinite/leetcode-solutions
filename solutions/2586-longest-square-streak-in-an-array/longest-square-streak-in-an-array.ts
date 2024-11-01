function longestSquareStreak(nums: number[]): number {
    // Convert nums to a sorted set to remove duplicates and have ordered numbers
    const numSet = new Set(nums);
    const sortedNums = Array.from(numSet).sort((a, b) => a - b);
    
    // Track the maximum streak length found
    let maxLength = 0;
    
    // Iterate through each number in sorted order
    for (const num of sortedNums) {
        // Initialize streak length for current number
        let length = 0;
        // Start with current number
        let current = num;
        
        // Keep squaring the number while it exists in our set
        while (numSet.has(current)) {
            length++;
            current = current ** 2;
            
            // Add safety check for numbers getting too large
            if (current > 100000) break;
        }
        
        // Only update maxLength if we found a streak of length > 1
        if (length > 1) {
            maxLength = Math.max(maxLength, length);
        }
    }
    
    // Return maxLength if we found a valid streak, otherwise return -1
    return maxLength > 1 ? maxLength : -1;
}