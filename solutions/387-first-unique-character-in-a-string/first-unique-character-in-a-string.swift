class Solution {
    func firstUniqChar(_ s: String) -> Int {
        let char = Array(s.unicodeScalars)
        var Freq = [Int](repeating: 0, count: 26)
        
        for first_unique_index in char.indices {
            Freq[Int(char[first_unique_index].value - 97)] += 1
        }
        for first_unique_index in char.indices {
            if Freq[Int(char[first_unique_index].value - 97)] == 1 {
                return first_unique_index
            }
        }
        
        return -1
    }
}