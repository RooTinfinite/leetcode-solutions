let BitMax = 24

class Solution {
    func largestCombination(_ candidates: [Int]) -> Int {
        var maxSet = 1
        var mask = 1
        
        for shift in 0..<BitMax {
            var count = 0
            for num in candidates {
                if (num & mask) != 0 {
                    count += 1
                }
            }
            if maxSet < count {
                maxSet = count
            }
            mask <<= 1
        }
        return maxSet
    }
}
