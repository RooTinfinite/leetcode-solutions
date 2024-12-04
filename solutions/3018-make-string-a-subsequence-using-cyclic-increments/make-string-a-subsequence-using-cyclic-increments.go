func canMakeSubsequence(source string, target string) bool {
    targetIdx, targetLen := 0, len(target)
    
    for _, currChar := range source {
        if targetIdx < targetLen && (int(target[targetIdx]) - int(currChar) + 26) % 26 <= 1 {
            targetIdx++
        }
    }
    return targetIdx == targetLen
}