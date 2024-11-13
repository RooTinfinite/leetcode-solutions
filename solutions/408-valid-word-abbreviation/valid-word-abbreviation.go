func validWordAbbreviation(word string, abbr string) bool {
    i, j := 0, 0
    for i < len(word) && j < len(abbr) {
        if abbr[j] >= '0' && abbr[j] <= '9' {
            if abbr[j] == '0' {
                return false
            }
            num := 0
            for j < len(abbr) && abbr[j] >= '0' && abbr[j] <= '9' {
                num = num * 10 + int(abbr[j] - '0')
                j++
            }
            i += num
        } else {
            if word[i] != abbr[j] {
                return false
            }
            i++
            j++
        }
    }
    return i == len(word) && j == len(abbr)
}