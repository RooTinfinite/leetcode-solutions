class Solution {
    func compressedString(_ word: String) -> String {
        // Handle empty string case
        guard !word.isEmpty else { return "" }
        
        // Initialize result string
        var comp = ""
        comp.reserveCapacity(word.count * 2)
        
        // Initialize counter and first character
        var cnt = 1
        var ch = word.first!
        
        // Iterate through string starting from second character
        let chars = Array(word)
        for i in 1..<chars.count {
            // If current character matches previous and count < 9
            // increment counter
            if chars[i] == ch && cnt < 9 {
                cnt += 1
            } else {
                // If character changes or count reaches 9
                // append count and character to result
                comp.append(String(cnt))    // Convert count to string and append
                comp.append(ch)             // Append the character
                ch = chars[i]               // Update current character
                cnt = 1                     // Reset counter for new character
            }
        }
        
        // Handle the last group of characters
        comp.append(String(cnt))    // Append final count
        comp.append(ch)             // Append final character
        
        return comp
    }
}