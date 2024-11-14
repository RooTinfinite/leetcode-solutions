func minimizedMaximum(storeCount int, productQuantities []int) int {
    maxQuantity := 0
    for _, q := range productQuantities {
        if q > maxQuantity {
            maxQuantity = q
        }
    }
    
    left := 1
    right := maxQuantity
    result := 0
    
    for left <= right {
        mid := left + (right-left)/2
        if canDistributeProducts(mid, storeCount, productQuantities) {
            result = mid
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    
    return result
}

func canDistributeProducts(maxProductsPerStore int, storeCount int, quantities []int) bool {
    requiredStores := 0
    
    for _, quantity := range quantities {
        requiredStores += (quantity + maxProductsPerStore - 1) / maxProductsPerStore
    }
    
    return requiredStores <= storeCount
}
