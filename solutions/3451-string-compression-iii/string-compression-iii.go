func compressedString(word string) string {
    // Handle empty string case
    if len(word) == 0 {
        return ""
    }
    
    // Initialize result builder with capacity to avoid reallocations
    var comp strings.Builder
    comp.Grow(len(word) * 2)
    
    // Initialize counter and first character
    cnt := 1
    ch := word[0]
    
    // Iterate through string starting from second character
    for i := 1; i < len(word); i++ {
        // If current character matches previous and count < 9
        // increment counter
        if word[i] == ch && cnt < 9 {
            cnt++
        } else {
            // If character changes or count reaches 9
            // append count and character to result
            comp.WriteByte(byte('0' + cnt)) // Convert count to byte and append
            comp.WriteByte(ch)              // Append the character
            ch = word[i]                    // Update current character
            cnt = 1                         // Reset counter for new character
        }
    }
    
    // Handle the last group of characters
    comp.WriteByte(byte('0' + cnt)) // Append final count
    comp.WriteByte(ch)              // Append final character
    
    return comp.String()
}