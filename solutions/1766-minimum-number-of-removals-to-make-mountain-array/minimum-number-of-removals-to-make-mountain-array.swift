class Solution {
    // Helper function to calculate LIS lengths for each position
    private func lisLength(_ v: [Int]) -> [Int] {
        // Start with first element
        var lis = [v[0]]
        // Track LIS length ending at each position
        var lisLen = Array(repeating: 1, count: v.count)
        
        for i in 1..<v.count {
            // If current element is larger than last LIS element, extend the sequence
            if v[i] > lis.last! {
                lis.append(v[i])
            } else {
                // Replace the smallest element that's >= current element
                // This maintains the potential for longer sequences
                let index = lis.firstIndex { $0 >= v[i] } ?? 0
                lis[index] = v[i]
            }
            // Store length of LIS up to current position
            lisLen[i] = lis.count
        }
        return lisLen
    }

    func minimumMountainRemovals(_ nums: [Int]) -> Int {
        let n = nums.count
        
        // Get LIS lengths from left to right (increasing part)
        let lis = lisLength(nums)
        
        // Get LIS lengths from right to left (decreasing part)
        let reversedNums = Array(nums.reversed())
        var lds = lisLength(reversedNums)
        lds.reverse()
        
        var removals = Int.max
        
        // For each potential peak position
        for i in 0..<n {
            // Valid mountain needs both sides to have length > 1
            if lis[i] > 1 && lds[i] > 1 {
                // Calculate removals needed:
                // Total length - (increasing length + decreasing length - 1)
                // -1 because peak is counted twice
                removals = min(removals, n + 1 - lis[i] - lds[i])
            }
        }
        
        return removals
    }
}