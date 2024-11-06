/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canSortArray = function(nums) {
    const n = nums.length;
    
    // Create a copy of input array
    const values = [...nums];
    
    // Helper function to count set bits
    const countBits = (num) => {
        let count = 0;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    };
    
    // Forward pass - check and swap from left to right
    for (let i = 0; i < n - 1; i++) {
        if (values[i] <= values[i + 1]) continue;
        else {
            if (countBits(values[i]) === countBits(values[i + 1])) {
                // Swap elements
                [values[i], values[i + 1]] = [values[i + 1], values[i]];
            } 
            else return false;
        }
    }
    
    // Backward pass - check and swap from right to left
    for (let i = n - 1; i >= 1; i--) {
        if (values[i] >= values[i - 1]) continue;
        else {
            if (countBits(values[i]) === countBits(values[i - 1])) {
                // Swap elements
                [values[i], values[i - 1]] = [values[i - 1], values[i]];
            } 
            else return false;
        }
    }
    
    return true;
};