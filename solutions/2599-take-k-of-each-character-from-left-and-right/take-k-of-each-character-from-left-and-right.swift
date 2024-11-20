class Solution {
    func takeCharacters(_ s: String, _ k: Int) -> Int {
        // Total counts
        var count = [0, 0, 0]
        let chars = Array(s)
        for c in chars {
            count[Int(c.asciiValue! - Character("a").asciiValue!)] += 1
        }
        
        if count.min()! < k {
            return -1
        }
        
        // Sliding Window
        var res = Int.max
        var l = 0
        for r in 0..<chars.count {
            count[Int(chars[r].asciiValue! - Character("a").asciiValue!)] -= 1
            
            while count.min()! < k {
                count[Int(chars[l].asciiValue! - Character("a").asciiValue!)] += 1
                l += 1
            }
            res = min(res, chars.count - (r - l + 1))
        }
        return res
    }
}