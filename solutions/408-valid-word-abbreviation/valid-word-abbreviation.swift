class Solution {
    func validWordAbbreviation(_ word: String, _ abbr: String) -> Bool {
        let word = Array(word)
        let abbr = Array(abbr)
        var i = 0, j = 0
       
        while i < word.count && j < abbr.count {
            if abbr[j].isNumber {
                if abbr[j] == "0" { return false }
                var num = 0
                while j < abbr.count && abbr[j].isNumber {
                    num = num * 10 + Int(String(abbr[j]))!
                    j += 1
                }
                i += num
            } else {
                if word[i] != abbr[j] { return false }
                i += 1
                j += 1
            }
        }
        return i == word.count && j == abbr.count
    }
}