func maximumBeauty(items [][]int, queries []int) []int {
    // Step 1: Sort items by price in ascending order
    sort.Slice(items, func(i, j int) bool {
        return items[i][0] < items[j][0]
    })
    
    n := len(items)
    // Step 2: Extract prices and beauties into separate slices
    prices := make([]int, n)
    beauties := make([]int, n)
    for i, item := range items {
        prices[i] = item[0]
        beauties[i] = item[1]
    }
    
    // Step 3: Create running maximum beauty array
    maxBeauties := make([]int, n+1)
    for i := 0; i < n; i++ {
        maxBeauties[i+1] = max(maxBeauties[i], beauties[i])
    }
    
    // Step 4: Process each query using binary search
    result := make([]int, len(queries))
    for i, query := range queries {
        index := sort.SearchInts(prices, query+1)
        result[i] = maxBeauties[index]
    }
    
    return result
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}