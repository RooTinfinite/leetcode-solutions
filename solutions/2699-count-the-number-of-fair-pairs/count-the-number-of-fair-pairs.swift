class Solution {
    private func binSearch(_ nums: [Int], _ l: Int, _ r: Int, _ target: Int) -> Int {
        var left = l
        var right = r
        while left <= right {
            let m = left + (right - left) / 2
            if nums[m] >= target {
                right = m - 1
            } else {
                left = m + 1
            }
        }
        return right
    }
    
    func countFairPairs(_ nums: [Int], _ lower: Int, _ upper: Int) -> Int {
        let sortedNums = nums.sorted()
        var res = 0
        for i in 0..<sortedNums.count {
            let low = lower - sortedNums[i]
            let up = upper - sortedNums[i]
            res += binSearch(sortedNums, i + 1, sortedNums.count - 1, up + 1) - 
                   binSearch(sortedNums, i + 1, sortedNums.count - 1, low)
        }
        return res
    }
}