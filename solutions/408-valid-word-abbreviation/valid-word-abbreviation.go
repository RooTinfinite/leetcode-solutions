func parseNumber(abbreviation string, startPos int) int {
    number := 0
    for startPos < len(abbreviation) && unicode.IsDigit(rune(abbreviation[startPos])) {
        number = number * 10 + int(abbreviation[startPos] - '0')
        startPos++
    }
    return number
}

func validWordAbbreviation(word string, abbreviation string) bool {
    wordPos, abbrPos := 0, 0
    
    for abbrPos < len(abbreviation) && wordPos < len(word) {
        if unicode.IsLetter(rune(abbreviation[abbrPos])) {
            if abbreviation[abbrPos] != word[wordPos] {
                return false
            }
            wordPos++
            abbrPos++
        } else {
            if abbreviation[abbrPos] == '0' {
                return false
            }
            
            skipCount := parseNumber(abbreviation, abbrPos)
            abbrPos += len(strconv.Itoa(skipCount))
            wordPos += skipCount
        }
    }
    
    return abbrPos == len(abbreviation) && wordPos == len(word)
}