func makeFancyString(s string) string {
    // Convert string to rune slice for easier manipulation
    chars := []rune(s)
    
    if len(chars) < 3 {
        return s
    }
    
    j := 2
    
    for i := 2; i < len(chars); i++ {
        if chars[i] != chars[j-1] || chars[i] != chars[j-2] {
            chars[j] = chars[i]
            j++
        }
    }
    
    return string(chars[:j])
}