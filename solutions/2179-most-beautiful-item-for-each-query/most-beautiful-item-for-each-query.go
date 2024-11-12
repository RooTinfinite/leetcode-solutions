func maximumBeauty(items [][]int, queries []int) []int {
    sort.Slice(items, func(i, j int) bool {
        return items[i][0] < items[j][0]
    })
    
    n := len(items)
    maxBeauties := make([]int, n)
    maxBeauties[0] = items[0][1]
    
    for i := 1; i < n; i++ {
        maxBeauties[i] = max(maxBeauties[i-1], items[i][1])
    }
    
    binarySearch := func(target int) int {
        left, right := 0, len(items)-1
        result := -1
        
        for left <= right {
            mid := left + (right-left)/2
            if items[mid][0] <= target {
                result = mid
                left = mid + 1
            } else {
                right = mid - 1
            }
        }
        return result
    }
    
    result := make([]int, len(queries))
    for i, query := range queries {
        idx := binarySearch(query)
        if idx < 0 {
            result[i] = 0
        } else {
            result[i] = maxBeauties[idx]
        }
    }
    
    return result
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}