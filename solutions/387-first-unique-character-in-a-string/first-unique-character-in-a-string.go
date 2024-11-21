func firstUniqChar(inputStr string) int {
    firstUnique := math.MaxInt32
    
    for c := 'a'; c <= 'z'; c++ {
        if strings.Contains(inputStr, string(c)) {
            if strings.Index(inputStr, string(c)) == strings.LastIndex(inputStr, string(c)) {
                firstUnique = min(firstUnique, strings.Index(inputStr, string(c)))
            }
        }
    }
    
    if firstUnique == math.MaxInt32 {
        return -1
    }
    return firstUnique
}