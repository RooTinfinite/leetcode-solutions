class Solution {
    func isPrefixOfWord(_ sentence: String, _ searchWord: String) -> Int {
        let words = sentence.split(separator: " ")
        for (index, word) in words.enumerated() {
            if word.hasPrefix(searchWord) {
                return index + 1
            }
        }
        return -1
    }
}