class Solution {
    func isCircularSentence(_ sentence: String) -> Bool {
        // Handle empty string case
        guard !sentence.isEmpty else { return true }
        
        let chars = Array(sentence)
        let n = chars.count
        
        // Handle single character case
        guard n > 1 else { return true }
        
        // First check: Compare first and last character
        if chars[0] != chars[n-1] {
            return false
        }
        
        // Check characters around spaces
        for i in 1..<(n-1) {
            if chars[i] == " " {
                // Ensure we're not accessing out of bounds
                let prevChar = chars[i-1]
                let nextChar = chars[i+1]
                if prevChar != nextChar {
                    return false
                }
            }
        }
        
        return true
    }
}