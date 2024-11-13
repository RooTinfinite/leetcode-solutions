class Solution {
    private func parseNumber(_ abbreviation: String, _ startPos: Int) -> Int {
        var number = 0
        var pos = startPos
        let chars = Array(abbreviation)
        while pos < chars.count && chars[pos].isNumber {
            number = number * 10 + Int(String(chars[pos]))!
            pos += 1
        }
        return number
    }
    
    func validWordAbbreviation(_ word: String, _ abbreviation: String) -> Bool {
        var wordPos = 0
        var abbrPos = 0
        let wordChars = Array(word)
        let abbrChars = Array(abbreviation)
        
        while abbrPos < abbrChars.count && wordPos < wordChars.count {
            if abbrChars[abbrPos].isLetter {
                if abbrChars[abbrPos] != wordChars[wordPos] {
                    return false
                }
                wordPos += 1
                abbrPos += 1
            } else {
                if abbrChars[abbrPos] == "0" {
                    return false
                }
                
                let skipCount = parseNumber(abbreviation, abbrPos)
                abbrPos += String(skipCount).count
                wordPos += skipCount
            }
        }
        
        return abbrPos == abbrChars.count && wordPos == wordChars.count
    }
}