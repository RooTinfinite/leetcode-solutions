class Solution {
    func addSpaces(_ s: String, _ spaces: [Int]) -> String {
        let m = spaces.count
        let n = s.count
        var t = Array(repeating: " ", count: n + m)
        var j = 0
        
        let sArray = Array(s)
        for i in 0..<n {
            if j < m && i == spaces[j] {
                j += 1
            }
            t[i + j] = String(sArray[i])
        }
        
        return t.joined()
    }
}