class Solution {
    func shortestSubarray(_ nums: [Int], _ k: Int) -> Int {
        var res = Int.max
        var curSum = 0
        // Queue will store tuples of (prefixSum, endIndex)
        var queue = [(Int, Int)]()
        
        for r in 0..<nums.count {
            curSum += nums[r]
            if curSum >= k {
                res = min(res, r + 1)
            }
            
            // Find the minimum valid window ending at r
            while !queue.isEmpty && curSum - queue[0].0 >= k {
                let (prefix, endIdx) = queue.removeFirst()
                res = min(res, r - endIdx)
            }
            
            // Validate the monotonic deque
            while !queue.isEmpty && queue[queue.count - 1].0 > curSum {
                queue.removeLast()
            }
            queue.append((curSum, r))
        }
        
        return res == Int.max ? -1 : res
    }
}