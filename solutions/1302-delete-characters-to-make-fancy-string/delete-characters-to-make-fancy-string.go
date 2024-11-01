func makeFancyString(s string) string {
    // Convert string to rune slice since Go strings are immutable
    // and we need to modify characters
    chars := []rune(s)
    
    // If string length is less than 3, it can't have
    // three consecutive same characters, so return as-is
    if len(chars) < 3 {
        return s
    }
    
    // j tracks where to place the next valid character
    // Start from position 2 since we need to look at previous 2 chars
    j := 2
    
    // Iterate through string starting from third character
    for i := 2; i < len(chars); i++ {
        // Add current character if it differs from either
        // of the two previous characters at positions j-1 and j-2
        // This ensures we never have more than two consecutive same chars
        if chars[i] != chars[j-1] || chars[i] != chars[j-2] {
            chars[j] = chars[i]
            j++
        }
    }
    
    // Convert back to string, taking only the valid portion
    // j represents the new length of our fancy string
    return string(chars[:j])
}