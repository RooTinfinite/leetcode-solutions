class Solution {
    func takeCharacters(_ s: String, _ k: Int) -> Int {
        var freq = [0, 0, 0]
        let chars = Array(s)
        let n = chars.count
        
        for c in chars {
            freq[Int(c.asciiValue! - Character("a").asciiValue!)] += 1
        }
        
        if freq[0] < k || freq[1] < k || freq[2] < k {
            return -1
        }
        
        var curr = [0, 0, 0]
        var maxLen = 0
        var left = 0
        
        for right in 0..<n {
            curr[Int(chars[right].asciiValue! - Character("a").asciiValue!)] += 1
            
            while left <= right && (curr[0] > freq[0] - k ||
                   curr[1] > freq[1] - k ||
                   curr[2] > freq[2] - k) {
                curr[Int(chars[left].asciiValue! - Character("a").asciiValue!)] -= 1
                left += 1
            }
            
            maxLen = max(maxLen, right - left + 1)
        }
        
        return n - maxLen
    }
}