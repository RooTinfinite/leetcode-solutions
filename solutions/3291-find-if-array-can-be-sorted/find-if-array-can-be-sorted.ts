function canSortArray(nums: number[]): boolean {
    const n: number = nums.length;
    
    // Create a copy of input array to work with
    const values: number[] = [...nums];

    // Forward pass - check and swap from left to right
    for (let i = 0; i < n - 1; i++) {
        // Skip if elements are already in order
        if (values[i] <= values[i + 1]) continue;
        else {
            // Check if adjacent elements have same number of set bits
            if (countBits(values[i]) === countBits(values[i + 1])) {
                // Swap elements if they have same number of set bits
                [values[i], values[i + 1]] = [values[i + 1], values[i]];
            } 
            else return false; // Cannot swap elements with different number of set bits
        }
    }

    // Backward pass - check and swap from right to left
    for (let i = n - 1; i >= 1; i--) {
        // Skip if elements are already in order
        if (values[i] >= values[i - 1]) continue;
        else {
            // Check if adjacent elements have same number of set bits
            if (countBits(values[i]) === countBits(values[i - 1])) {
                // Swap elements if they have same number of set bits
                [values[i], values[i - 1]] = [values[i - 1], values[i]];
            } 
            else return false; // Cannot swap elements with different number of set bits
        }
    }

    // Array can be sorted if we reach here
    return true;
}

// Helper function to count set bits (1's) in a number
function countBits(num: number): number {
    let count = 0;
    while (num) {
        count += num & 1;
        num >>>= 1;
    }
    return count;
}