func addSpaces(s string, spaces []int) string {
    result := make([]byte, len(s)+len(spaces))
    writePos := 0
    readPos := 0
    
    for _, spacePos := range spaces {
        for readPos < spacePos {
            result[writePos] = s[readPos]
            writePos++
            readPos++
        }
        result[writePos] = ' '
        writePos++
    }
    
    for readPos < len(s) {
        result[writePos] = s[readPos]
        writePos++
        readPos++
    }
    
    return string(result)
}