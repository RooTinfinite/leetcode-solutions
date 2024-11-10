class Solution {
    func minimumSubarrayLength(_ nums: [Int], _ k: Int) -> Int {
        var ans = Int.max
        var s = 0
        var left = 0
        var cnt = Array(repeating: 0, count: 32)
        
        for right in 0..<nums.count {
            let num = nums[right]
            s |= num
            var i = 0
            var temp = num
            while temp > 0 {
                cnt[i] += temp % 2
                temp /= 2
                i += 1
            }
            
            while s >= k && left <= right {
                ans = min(right - left + 1, ans)
                temp = nums[left]
                i = 0
                while temp > 0 {
                    if temp % 2 == 1 {
                        cnt[i] -= 1
                        if cnt[i] == 0 {
                            s ^= 1 << i
                        }
                    }
                    temp /= 2
                    i += 1
                }
                left += 1
            }
        }
        return ans == Int.max ? -1 : ans
    }
}