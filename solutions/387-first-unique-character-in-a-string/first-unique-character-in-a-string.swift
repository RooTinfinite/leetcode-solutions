class Solution {
    func firstUniqChar(_ inputStr: String) -> Int {
        var firstUnique = Int.max
        
        for ascii in Character("a").asciiValue!...Character("z").asciiValue! {
            let char = String(UnicodeScalar(ascii))
            if inputStr.contains(char) {
                if inputStr.firstIndex(of: Character(char)) == inputStr.lastIndex(of: Character(char)) {
                    if let index = inputStr.firstIndex(of: Character(char)) {
                        firstUnique = min(firstUnique, inputStr.distance(from: inputStr.startIndex, to: index))
                    }
                }
            }
        }
        
        return firstUnique != Int.max ? firstUnique : -1
    }
}