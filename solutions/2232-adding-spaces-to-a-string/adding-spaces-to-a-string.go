func addSpaces(s string, spaces []int) string {
    var res strings.Builder
    res.Grow(len(s) + len(spaces))
    
    i, j := 0, 0
    for i < len(s) && j < len(spaces) {
        if i < spaces[j] {
            res.WriteByte(s[i])
            i++
        } else {
            res.WriteByte(' ')
            j++
        }
    }
    
    if i < len(s) {
        res.WriteString(s[i:])
    }
    
    return res.String()
}