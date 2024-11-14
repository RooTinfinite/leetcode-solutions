class Solution {
    func minEatingSpeed(_ piles: [Int], _ h: Int) -> Int {
        var left: Int = 1
        var right: Int = piles.max() ?? 0
        
        while left < right {
            let mid = left + (right - left) / 2
            
            if canEatAll(piles, h, mid) {
                right = mid
            } else {
                left = mid + 1
            }
        }
        
        return left
    }
    
    private func canEatAll(_ piles: [Int], _ h: Int, _ k: Int) -> Bool {
        var hours = 0
        for pile in piles {
            hours += (pile + k - 1) / k
            if hours > h { return false }
        }
        return true
    }
}