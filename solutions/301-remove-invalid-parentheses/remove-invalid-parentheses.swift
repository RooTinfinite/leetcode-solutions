class Solution {
    func removeInvalidParentheses(_ s: String) -> [String] {
        func isValid(_ str: String) -> Bool {
            var count = 0
            for char in str {
                if char == "(" { count += 1 }
                else if char == ")" {
                    if count == 0 { return false }
                    count -= 1
                }
            }
            return count == 0
        }
        
        var result = [String]()
        var visited = Set<String>()
        var queue = [s]
        visited.insert(s)
        var found = false
        
        while !queue.isEmpty {
            let curr = queue.removeFirst()
            
            if isValid(curr) {
                result.append(curr)
                found = true
            }
            
            if found { continue }
            
            let chars = Array(curr)
            for i in 0..<chars.count {
                if chars[i] != "(" && chars[i] != ")" { continue }
                var nextChars = chars
                nextChars.remove(at: i)
                let nextState = String(nextChars)
                
                if !visited.contains(nextState) {
                    visited.insert(nextState)
                    queue.append(nextState)
                }
            }
        }
        return result
    }
}