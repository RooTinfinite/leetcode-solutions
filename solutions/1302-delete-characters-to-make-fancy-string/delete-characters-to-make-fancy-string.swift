class Solution {
    func makeFancyString(_ s: String) -> String {
        // Convert string to array for easier manipulation
        var chars = Array(s)
        
        // Return original string if length is less than 3
        if chars.count < 3 {
            return s
        }
        
        // j keeps track of the position where we'll place
        // the next valid character
        var j = 2
        
        // Iterate through string starting from index 2
        for i in 2..<chars.count {
            // Add current character if it's different from
            // either of the two previous characters
            if chars[i] != chars[j-1] || chars[i] != chars[j-2] {
                chars[j] = chars[i]
                j += 1
            }
        }
        
        // Create new string from the modified array up to index j
        return String(chars[0..<j])
    }
}