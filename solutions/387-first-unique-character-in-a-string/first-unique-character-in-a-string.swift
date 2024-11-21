class Solution {
    func firstUniqChar(_ s: String) -> Int {
        var firstUnique: [Int] = []
        
        for letter in "abcdefghijklmnopqrstuvwxyz" {
            let count = s.filter { $0 == letter }.count
            if count == 1 {
                if let index = s.firstIndex(of: letter) {
                    firstUnique.append(s.distance(from: s.startIndex, to: index))
                }
            }
        }
        
        return firstUnique.min() ?? -1
    }
}