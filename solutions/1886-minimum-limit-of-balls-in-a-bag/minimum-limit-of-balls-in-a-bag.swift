class Solution {
    private func canDivide(_ nums: [Int], _ maxBalls: Int, _ maxOperations: Int) -> Bool {
        var ops = 0
        for n in nums {
            ops += (n + maxBalls - 1) / maxBalls - 1
            if ops > maxOperations { return false }
        }
        return true
    }
    
    func minimumSize(_ nums: [Int], _ maxOperations: Int) -> Int {
        var left = 1
        var right = nums.max()!
        var res = right
        
        while left < right {
            let mid = left + (right - left) / 2
            if canDivide(nums, mid, maxOperations) {
                right = mid
                res = right
            } else {
                left = mid + 1
            }
        }
        return res
    }
}