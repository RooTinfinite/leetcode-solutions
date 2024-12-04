func canMakeSubsequence(source string, target string) bool {
    srcLen, tgtLen := len(source), len(target)
    targetChar := target[0]
    
    srcIdx, tgtIdx := 0, 0
    for srcIdx < srcLen && tgtIdx < tgtLen {
        srcChar := source[srcIdx]
        
        if srcChar == targetChar || 
           srcChar + 1 == targetChar || 
           (srcChar == 'z' && targetChar == 'a') {
            tgtIdx++
            if tgtIdx < tgtLen {
                targetChar = target[tgtIdx]
            }
        }
        
        srcIdx++
    }
    
    return tgtIdx == tgtLen
}