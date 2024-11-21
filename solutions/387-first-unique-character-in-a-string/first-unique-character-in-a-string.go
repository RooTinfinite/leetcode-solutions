func firstUniqChar(s string) int {
    firstUnique := make([]int, 0)
    letters := "abcdefghijklmnopqrstuvwxyz"
    
    for _, letter := range letters {
        count := strings.Count(s, string(letter))
        if count == 1 {
            firstUnique = append(firstUnique, strings.IndexRune(s, letter))
        }
    }
    
    if len(firstUnique) == 0 {
        return -1
    }
    
    minIndex := firstUnique[0]
    for _, index := range firstUnique {
        if index < minIndex {
            minIndex = index
        }
    }
    return minIndex
}