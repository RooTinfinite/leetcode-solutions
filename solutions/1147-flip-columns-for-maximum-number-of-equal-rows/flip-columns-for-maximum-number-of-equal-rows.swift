class Solution {
    func maxEqualRowsAfterFlips(_ matrix: [[Int]]) -> Int {
        var count: [String: Int] = [:]
        
        for row in matrix {
            var key = ""
            for (i, num) in row.enumerated() {
                key += String(row[0] == 1 ? 1 - num : num)
            }
            count[key, default: 0] += 1
        }
        
        return count.values.max() ?? 0
    }
}