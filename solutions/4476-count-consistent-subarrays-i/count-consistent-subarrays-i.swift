class Solution {
    func countConsistent(_ nums: [Int]) -> Int {
        let n = nums.count
        var cnt = 0
        for i in 0..<n {
            var add = nums[i]
            var minVal = nums[i]
            for j in i..<n {
                add &= nums[j]
                if nums[j] < minVal {
                    minVal = nums[j]
                }
                if add == minVal {
                    cnt += 1
                }
            }
        }
        return cnt
    }
}