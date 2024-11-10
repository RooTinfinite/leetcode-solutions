class Solution {
    func minimumSubarrayLength(_ nums: [Int], _ k: Int) -> Int {
        if k == 0 {
            return 1
        }
        var shortest = nums.count + 1
        var count = Array(repeating: 0, count: 32)
        var val = 0
        var start = 0
        
        for i in 0..<nums.count {
            var num = nums[i]
            val |= num
            var ibit = 0
            while num != 0 {
                count[ibit] += num & 1
                num >>= 1
                ibit += 1
            }
            while val >= k && start < nums.count {
                shortest = min(shortest, i - start + 1)
                num = nums[start]
                start += 1
                ibit = 0
                while num != 0 {
                    count[ibit] -= num & 1
                    if count[ibit] == 0 {
                        val &= ~(1 << ibit)
                    }
                    num >>= 1
                    ibit += 1
                }
            }
        }
        return shortest == (nums.count + 1) ? -1 : shortest
    }
}