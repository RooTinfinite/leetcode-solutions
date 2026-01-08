func maxDotProduct(nums1 []int, nums2 []int) int {
    m, n := len(nums1), len(nums2)
    current := make([]int, n+1)
    previous := make([]int, n+1)
    for i := range current {
        current[i] = math.MinInt32
        previous[i] = math.MinInt32
    }

    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            currProduct := nums1[i-1] * nums2[j-1]
            current[j] = max(max(max(currProduct, previous[j]), current[j-1]), currProduct + max(0, previous[j-1]))
        }
        current, previous = previous, current
    }
    return previous[n]
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}