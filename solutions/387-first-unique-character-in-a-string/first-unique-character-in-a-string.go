func firstUniqChar(s string) int {
    count := make(map[rune]int)
    
    for _, c := range s {
        count[c]++
    }
    
    for i, c := range s {
        if count[c] == 1 {
            return i
        }
    }
    return -1
}