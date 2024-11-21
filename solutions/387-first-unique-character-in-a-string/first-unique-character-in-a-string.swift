class Solution {
    func firstUniqChar(_ s: String) -> Int {
        let str = Array(s.unicodeScalars)
        var alphabet = [Int](repeating: 0, count: 26)
        var index = 0

        for i in str.indices {
            alphabet[Int(str[i].value - 97)] += 1
        }

        for i in str.indices {
            if alphabet[Int(str[i].value - 97)] == 1 {
                return index
            }
            index += 1
        } 

        return -1
    }
}