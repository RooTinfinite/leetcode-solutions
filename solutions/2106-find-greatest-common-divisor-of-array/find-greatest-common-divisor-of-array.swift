class Solution {
    func findGCD(_ nums: [Int]) -> Int {
        var mn = nums[0], mx = nums[0]
        for x in nums {
            if x < mn { mn = x }
            if x > mx { mx = x }
        }
        var a = mn, b = mx
        while b != 0 {
            let t = a % b
            a = b
            b = t
        }
        return a
    }
}