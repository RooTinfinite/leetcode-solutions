class Solution {
    func countFairPairs(_ nums: [Int], _ lower: Int, _ upper: Int) -> Int {
        let sortedNums = nums.sorted()
        
        func countPairs(_ target: Int) -> Int {
            var left = 0
            var right = sortedNums.count - 1
            var count = 0
            
            while left < right {
                let currentSum = sortedNums[left] + sortedNums[right]
                if currentSum <= target {
                    count += right - left
                    left += 1
                } else {
                    right -= 1
                }
            }
            return count
        }
        
        return countPairs(upper) - countPairs(lower - 1)
    }
}