class Solution {
    func minimizedMaximum(_ storeCount: Int, _ productQuantities: [Int]) -> Int {
        let maxQuantity = productQuantities.max()!
        var left = 1
        var right = maxQuantity
        var result = 0
        
        while left <= right {
            let mid = left + (right - left) / 2
            if canDistributeProducts(mid, storeCount, productQuantities) {
                result = mid
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        
        return result
    }
    
    private func canDistributeProducts(_ maxProductsPerStore: Int, _ storeCount: Int, _ quantities: [Int]) -> Bool {
        var requiredStores = 0
        
        for quantity in quantities {
            requiredStores += (quantity + maxProductsPerStore - 1) / maxProductsPerStore
        }
        
        return requiredStores <= storeCount
    }
}
