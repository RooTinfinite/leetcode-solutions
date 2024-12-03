class Solution {
    func addSpaces(_ s: String, _ spaces: [Int]) -> String {
       var result = ""
       var s = Array(s)
       var sIndex = 0
       for i in 0..<s.count {
        if sIndex < spaces.count && i == spaces[sIndex] {
            result += " "
            sIndex += 1
        }
        result.append(s[i])
       }
       return result
    }
}