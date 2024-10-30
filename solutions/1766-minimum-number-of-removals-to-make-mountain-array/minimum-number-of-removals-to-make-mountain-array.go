func lisLength(v []int) []int {
    // Start with first element
    lis := []int{v[0]}
    // Track LIS length ending at each position
    lisLen := make([]int, len(v))
    for i := range lisLen {
        lisLen[i] = 1
    }

    for i := 1; i < len(v); i++ {
        // If current element is larger than last LIS element, extend the sequence
        if v[i] > lis[len(lis)-1] {
            lis = append(lis, v[i])
        } else {
            // Replace the smallest element that's >= current element
            index := sort.SearchInts(lis, v[i])
            lis[index] = v[i]
        }
        // Store length of LIS up to current position
        lisLen[i] = len(lis)
    }
    return lisLen
}

func minimumMountainRemovals(nums []int) int {
    n := len(nums)
    
    // Get LIS lengths from left to right (increasing part)
    lis := lisLength(nums)
    
    // Get LIS lengths from right to left (decreasing part)
    // Create reversed copy of nums
    reversed := make([]int, n)
    copy(reversed, nums)
    for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
        reversed[i], reversed[j] = reversed[j], reversed[i]
    }
    
    lds := lisLength(reversed)
    // Reverse lds
    for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
        lds[i], lds[j] = lds[j], lds[i]
    }
    
    removals := math.MaxInt32
    
    // For each potential peak position
    for i := 0; i < n; i++ {
        // Valid mountain needs both sides to have length > 1
        if lis[i] > 1 && lds[i] > 1 {
            // Calculate removals needed:
            // Total length - (increasing length + decreasing length - 1)
            // -1 because peak is counted twice
            removals = min(removals, n+1-lis[i]-lds[i])
        }
    }
    
    return removals
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}