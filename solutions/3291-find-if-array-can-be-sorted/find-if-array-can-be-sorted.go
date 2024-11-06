func canSortArray(nums []int) bool {
    n := len(nums)
    
    // Create a copy of input array
    values := make([]int, n)
    copy(values, nums)

    // Forward pass - check and swap from left to right
    for i := 0; i < n-1; i++ {
        // Skip if elements are already in order
        if values[i] <= values[i+1] {
            continue
        } else {
            // Check if adjacent elements have same number of set bits
            if bits.OnesCount(uint(values[i])) == bits.OnesCount(uint(values[i+1])) {
                // Swap elements if they have same number of set bits
                values[i], values[i+1] = values[i+1], values[i]
            } else {
                return false // Cannot swap elements with different number of set bits
            }
        }
    }

    // Backward pass - check and swap from right to left
    for i := n - 1; i >= 1; i-- {
        // Skip if elements are already in order
        if values[i] >= values[i-1] {
            continue
        } else {
            // Check if adjacent elements have same number of set bits
            if bits.OnesCount(uint(values[i])) == bits.OnesCount(uint(values[i-1])) {
                // Swap elements if they have same number of set bits
                values[i], values[i-1] = values[i-1], values[i]
            } else {
                return false // Cannot swap elements with different number of set bits
            }
        }
    }

    // Array can be sorted if we reach here
    return true
}