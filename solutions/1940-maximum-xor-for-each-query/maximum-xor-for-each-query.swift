class Solution {
    func getMaximumXor(_ nums: [Int], _ maximumBit: Int) -> [Int] {
        let mask = (1 << maximumBit) - 1
        let n = nums.count
        var res = Array(repeating: 0, count: n)
        var curr = 0
        
        for i in 0..<n {
            curr ^= nums[i]
            res[n-i-1] = ~curr & mask
        }
        
        return res
    }
}