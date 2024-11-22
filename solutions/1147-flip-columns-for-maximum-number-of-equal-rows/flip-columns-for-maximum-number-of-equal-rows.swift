class Solution {
    func maxEqualRowsAfterFlips(_ mat: [[Int]]) -> Int {
        var patFreq: [String: Int] = [:]
        
        for row in mat {
            var pattern = ""
            if row[0] == 0 {
                pattern = row.map { String($0) }.joined()
            } else {
                pattern = row.map { String($0 ^ 1) }.joined()
            }
            patFreq[pattern, default: 0] += 1
        }
        
        return patFreq.values.max() ?? 0
    }
}