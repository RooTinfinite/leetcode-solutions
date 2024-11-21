class Solution {
    func firstUniqChar(_ s: String) -> Int {
        var count: [Character: Int] = [:]
        
        for c in s {
            count[c, default: 0] += 1
        }
        
        for (i, c) in s.enumerated() {
            if count[c] == 1 {
                return i
            }
        }
        return -1
    }
}